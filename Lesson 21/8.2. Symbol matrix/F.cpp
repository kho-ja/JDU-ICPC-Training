#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h, n;
    cin >> w >> h >> n;

    vector<vector<char>> a(w, vector<char>(h)), b(w, vector<char>(h));

    for (auto& i : a)
        for (auto& j : i)
            cin >> j;

    while (n--) {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {

                int t = (i - 1 + w) % w;
                int bt = (i + 1) % w;
                int l = (j - 1 + h) % h;
                int r = (j + 1) % h;

                int cnt =
                    (a[t][j] == '*') +
                    (a[bt][j] == '*') +
                    (a[i][l] == '*') +
                    (a[i][r] == '*') +
                    (a[t][l] == '*') +
                    (a[t][r] == '*') +
                    (a[bt][l] == '*') +
                    (a[bt][r] == '*');

                if (cnt == 3 || (cnt == 2 && a[i][j] == '*'))
                    b[i][j] = '*';
                else
                    b[i][j] = '.';
            }
        }
        a = b;
    }

    for (auto& i : a) {
        for (auto& j : i)
            cout << j;
        cout << "\n";
    }

    return 0;
}