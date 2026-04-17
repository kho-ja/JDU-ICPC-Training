#include <iostream>
#include <tuple>
using namespace std;

int a[4][4];

bool hasWinner() {
    for (int i = 1; i <= 3; i++) {
        if (a[i][1] != 0 && a[i][1] == a[i][2] && a[i][2] == a[i][3])
            return true;
        if (a[1][i] != 0 && a[1][i] == a[2][i] && a[2][i] == a[3][i])
            return true;
    }
    if (a[1][1] != 0 && a[1][1] == a[2][2] && a[2][2] == a[3][3])
        return true;
    if (a[1][3] != 0 && a[1][3] == a[2][2] && a[2][2] == a[3][1])
        return true;
    return false;
}

int playGame(int round) { // -1 0 1
    if (hasWinner()) return -1;
    if (round == 10) return 0;

    bool isDraw = false;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (a[i][j] == 0) {
                a[i][j] = 2 - round % 2;
                int t = -playGame(round + 1);
                a[i][j] = 0;
                if (t == 1) return 1;
                if (t == 0) isDraw = true;
            }
        }
    }
    if (isDraw) return 0;
    return -1;
}

pair<int, int> bestMove(int round) {
    int I = 0, J = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (a[i][j] == 0) {
                a[i][j] = 2 - round % 2;
                int t = -playGame(round + 1);
                a[i][j] = 0;
                if (t == 1) return { i, j };
                if (t == 0 || I == 0) I = i, J = j;
            }
        }
    }
    return { I, J };
}

int main() {
    int k, x, y;
    cin >> k;
    for (int i = 1; i <= 9; i++) {
        if (2 - i % 2 == k) {
            tie(x, y) = bestMove(i);
            a[x][y] = k;
            cout << x << " " << y << "\n";
        }
        else {
            cin >> x >> y;
            a[x][y] = 3 - k;
        }
    }
    return 0;
}