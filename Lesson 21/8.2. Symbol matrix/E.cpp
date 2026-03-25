#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (auto& i : a) for (auto& j : i) cin >> j;

    for (int i = 0; i < n; i++) {
        for (int j = 0, x; j < m; j++) {
            cin >> x;
            if (a[i][j] == '.') continue;
            else if (a[i][j] == 'R' && x >= 4) continue;
            else if (a[i][j] == 'G' && x % 4 > 1) continue;
            else if (a[i][j] == 'B' && x % 2) continue;
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}