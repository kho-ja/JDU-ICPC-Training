#include <algorithm>
#include <chrono>
#include <csignal>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

using namespace std;

struct Pixel {
    char ch;
    int color;
};

enum class Mode {
    Glider,
    Swarm,
    Pulsar,
    Gun,
    Soup
};

static const char* modeName(Mode m) {
    switch (m) {
    case Mode::Glider:
        return "GLIDER";
    case Mode::Swarm:
        return "SWARM";
    case Mode::Pulsar:
        return "PULSAR";
    case Mode::Gun:
        return "GUN";
    case Mode::Soup:
        return "SOUP";
    }
    return "?";
}

static void restoreTerminal() {
    cout << "\x1b[0m\x1b[?25h\x1b[?1049l" << flush;
}

static void onSignal(int) {
    restoreTerminal();
    _Exit(0);
}

static void enableAnsi() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        return;
    }

    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode)) {
        return;
    }

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, mode);
#endif
}

static pair<int, int> terminalSize() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hOut, &csbi)) {
        int cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        return { cols, rows };
    }
    return { 100, 35 };
#else
    winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return { static_cast<int>(w.ws_col), static_cast<int>(w.ws_row) };
    }
    return { 100, 35 };
#endif
}

static bool pollKey(char& ch) {
#ifdef _WIN32
    if (_kbhit()) {
        ch = static_cast<char>(_getch());
        return true;
    }
#else
    (void)ch;
#endif
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    signal(SIGINT, onSignal);
    enableAnsi();
    cout << "\x1b[?1049h\x1b[2J\x1b[H\x1b[?25l";

    int rows = 0;
    int cols = 0;
    bool showUi = false;
    bool forceRedraw = true;
    int delayMs = 60;
    Mode mode = Mode::Gun;

    vector<vector<unsigned char>> board;
    vector<vector<unsigned char>> nextBoard;
    vector<vector<unsigned short>> age;
    vector<vector<Pixel>> prevPixels;
    vector<string> prevRows;
    vector<int> prevRowColors;

    unsigned int rng = static_cast<unsigned int>(
        chrono::high_resolution_clock::now().time_since_epoch().count());

    auto rnd = [&]() {
        rng ^= rng << 13;
        rng ^= rng >> 17;
        rng ^= rng << 5;
        return rng;
        };

    auto clearWorld = [&]() {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                board[r][c] = 0;
                nextBoard[r][c] = 0;
                age[r][c] = 0;
            }
        }
        };

    auto put = [&](const vector<string>& pat, int top, int left) {
        for (int r = 0; r < static_cast<int>(pat.size()); ++r) {
            for (int c = 0; c < static_cast<int>(pat[r].size()); ++c) {
                if (pat[r][c] == '*') {
                    int rr = (top + r + rows) % rows;
                    int cc = (left + c + cols) % cols;
                    board[rr][cc] = 1;
                    age[rr][cc] = 1;
                }
            }
        }
        };

    auto seed = [&]() {
        clearWorld();
        if (mode == Mode::Glider) {
            put({ ".*.", "..*", "***" }, rows / 2 - 1, cols / 2 - 1);
        }
        else if (mode == Mode::Swarm) {
            put({ ".*.", "..*", "***" }, rows / 5, cols / 5);
            put({ "***", "*..", ".*." }, rows / 5, cols * 4 / 5);
            put({ "***", "..*", ".*." }, rows * 4 / 5, cols / 3);
            put({ ".*.", "*..", "***" }, rows * 4 / 5, cols * 2 / 3);
            put({ ".*.", "..*", "***" }, rows / 2, cols / 2);
        }
        else if (mode == Mode::Pulsar) {
            int ro = rows / 2 - 7;
            int co = cols / 2 - 7;
            vector<pair<int, int>> p = {
                {0, 2}, {0, 3}, {0, 4}, {0, 8}, {0, 9}, {0, 10},
                {2, 0}, {3, 0}, {4, 0}, {2, 5}, {3, 5}, {4, 5}, {2, 7}, {3, 7}, {4, 7}, {2, 12}, {3, 12}, {4, 12},
                {5, 2}, {5, 3}, {5, 4}, {5, 8}, {5, 9}, {5, 10},
                {7, 2}, {7, 3}, {7, 4}, {7, 8}, {7, 9}, {7, 10},
                {8, 0}, {9, 0}, {10, 0}, {8, 5}, {9, 5}, {10, 5}, {8, 7}, {9, 7}, {10, 7}, {8, 12}, {9, 12}, {10, 12},
                {12, 2}, {12, 3}, {12, 4}, {12, 8}, {12, 9}, {12, 10}
            };
            for (const auto& x : p) {
                int rr = (ro + x.first + rows) % rows;
                int cc = (co + x.second + cols) % cols;
                board[rr][cc] = 1;
                age[rr][cc] = 1;
            }
        }
        else if (mode == Mode::Gun) {
            vector<pair<int, int>> gun = {
                {1, 25}, {2, 23}, {2, 25}, {3, 13}, {3, 14}, {3, 21}, {3, 22},
                {3, 35}, {3, 36}, {4, 12}, {4, 16}, {4, 21}, {4, 22}, {4, 35},
                {4, 36}, {5, 1}, {5, 2}, {5, 11}, {5, 17}, {5, 21}, {5, 22},
                {6, 1}, {6, 2}, {6, 11}, {6, 15}, {6, 17}, {6, 18}, {6, 23},
                {6, 25}, {7, 11}, {7, 17}, {7, 25}, {8, 12}, {8, 16}, {9, 13},
                {9, 14}
            };
            int ro = rows / 3;
            int co = cols / 4;
            for (const auto& g : gun) {
                int rr = (ro + g.first) % rows;
                int cc = (co + g.second) % cols;
                board[rr][cc] = 1;
                age[rr][cc] = 1;
            }
        }
        else {
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    // Balanced density: lively scene without overwhelming terminal output.
                    if ((rnd() % 1000) < 155) {
                        board[r][c] = 1;
                        age[r][c] = 1;
                    }
                }
            }
        }
        };

    auto resizeIfNeeded = [&]() {
        pair<int, int> t = terminalSize();
        int topPadding = showUi ? 1 : 0;
        int newRows = max(10, t.second - topPadding);
        int newCols = max(20, t.first);

        if (newRows != rows || newCols != cols) {
            rows = newRows;
            cols = newCols;
            board.assign(rows, vector<unsigned char>(cols, 0));
            nextBoard.assign(rows, vector<unsigned char>(cols, 0));
            age.assign(rows, vector<unsigned short>(cols, 0));
            prevPixels.assign(rows, vector<Pixel>(cols, { '\0', -1 }));
            prevRows.assign(rows, string());
            prevRowColors.assign(rows, -1);
            seed();
            forceRedraw = true;
            return true;
        }
        return false;
        };

    auto neighbors = [&](int r, int c) {
        int cnt = 0;
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0) {
                    continue;
                }
                int rr = (r + dr + rows) % rows;
                int cc = (c + dc + cols) % cols;
                cnt += board[rr][cc];
            }
        }
        return cnt;
        };

    auto liveColor = [](unsigned short a, long long g, int r, int c) {
        static const int palette[8] = { 39, 45, 51, 87, 123, 159, 195, 225 };
        int idx = static_cast<int>((a / 3 + g / 6 + (r + c) / 7) % 8);
        return palette[idx];
        };

    long long gen = 0;
    long long stableFrames = 0;
    const long long autoCycle = 1300;

    while (true) {
        resizeIfNeeded();

        char key = 0;
        while (pollKey(key)) {
            if (key == 'q' || key == 'Q') {
                restoreTerminal();
                cout << '\n';
                return 0;
            }
            if (key == 'm' || key == 'M') {
                mode = static_cast<Mode>((static_cast<int>(mode) + 1) % 5);
                seed();
                gen = 0;
                stableFrames = 0;
                forceRedraw = true;
            }
            if (key == '\t') {
                showUi = !showUi;
                forceRedraw = true;
                resizeIfNeeded();
            }
            if (key == '+') {
                delayMs = max(15, delayMs - 5);
            }
            if (key == '-') {
                delayMs = min(180, delayMs + 5);
            }
        }

        int alive = 0;
        bool same = true;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int n = neighbors(r, c);
                unsigned char now = board[r][c];
                unsigned char nxt = (n == 3 || (n == 2 && now)) ? 1 : 0;
                nextBoard[r][c] = nxt;
                alive += nxt;

                if (nxt) {
                    age[r][c] = static_cast<unsigned short>(min(60000, static_cast<int>(age[r][c]) + 1));
                }
                else if (age[r][c] > 0) {
                    age[r][c] -= 1;
                }

                if (nxt != now) {
                    same = false;
                }
            }
        }

        board.swap(nextBoard);
        ++gen;
        stableFrames = same ? stableFrames + 1 : 0;

        if (alive == 0 || stableFrames > 140 || gen % autoCycle == 0) {
            mode = static_cast<Mode>((static_cast<int>(mode) + 1) % 5);
            seed();
            gen = 0;
            stableFrames = 0;
            forceRedraw = true;
        }

        if (forceRedraw) {
            cout << "\x1b[2J";
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    prevPixels[r][c] = { '\0', -1 };
                }
                prevRows[r].clear();
                prevRowColors[r] = -1;
            }
            forceRedraw = false;
        }

        int topOffset = showUi ? 1 : 0;
        if (showUi) {
            cout << "\x1b[1;1H\x1b[2K";
            cout << "mode " << modeName(mode)
                << "  gen " << gen
                << "  speed " << delayMs << "ms"
                << "  [Tab] [M] [Q]";
        }

        bool heavyScene = (mode == Mode::Soup);
        if (heavyScene) {
            // Faster path for dense scenes: row-level diff writes with lightweight color waves.
            static const int soupPalette[6] = { 44, 45, 51, 87, 123, 159 };
            for (int r = 0; r < rows; ++r) {
                string line(cols, ' ');
                for (int c = 0; c < cols; ++c) {
                    if (board[r][c]) {
                        unsigned short a = age[r][c];
                        line[c] = (a < 3 ? 'o' : (a < 10 ? 'O' : '@'));
                    }
                    else if (age[r][c] > 7) {
                        line[c] = '.';
                    }
                    else if (age[r][c] > 3) {
                        line[c] = ',';
                    }
                    else {
                        line[c] = ' ';
                    }
                }

                int rowColor = soupPalette[(static_cast<int>(gen / 5) + r / 2) % 6];

                if (line != prevRows[r] || rowColor != prevRowColors[r]) {
                    cout << "\x1b[" << (r + 1 + topOffset) << ";1H"
                        << "\x1b[38;5;" << rowColor << "m"
                        << line << "\x1b[0m";
                    prevRows[r] = line;
                    prevRowColors[r] = rowColor;
                }
            }
        }
        else {
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    Pixel p;
                    if (board[r][c]) {
                        unsigned short a = age[r][c];
                        p.ch = (a < 4 ? 'o' : (a < 12 ? 'O' : '@'));
                        p.color = liveColor(a, gen, r, c);
                    }
                    else if (age[r][c] > 8) {
                        p.ch = '.';
                        p.color = 240;
                    }
                    else if (age[r][c] > 3) {
                        p.ch = ',';
                        p.color = 238;
                    }
                    else {
                        p.ch = ' ';
                        p.color = 0;
                    }

                    if (p.ch != prevPixels[r][c].ch || p.color != prevPixels[r][c].color) {
                        cout << "\x1b[" << (r + 1 + topOffset) << ';' << (c + 1) << 'H';
                        if (p.color > 0) {
                            cout << "\x1b[38;5;" << p.color << 'm' << p.ch << "\x1b[0m";
                        }
                        else {
                            cout << p.ch;
                        }
                        prevPixels[r][c] = p;
                    }
                }
            }
        }

        cout.flush();
        int effectiveDelay = (mode == Mode::Soup) ? max(20, delayMs - 15) : delayMs;
        this_thread::sleep_for(chrono::milliseconds(effectiveDelay));
    }

    return 0;
}
