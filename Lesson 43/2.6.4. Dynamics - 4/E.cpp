#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

// vector<vector<bool>> color;
// int n, m, res = 0;

// void backtracking(int row, int col) {
//     if (col == m) {
//         col = 0;
//         row++;
//     }
//     if (row == n) {
//         res++;
//         return;
//     }
//     if (row == 0 || col == 0 || color[row-1][col-1] || color[row-1][col] || color[row][col-1]) {
//         color[row][col] = false;
//         backtracking(row, col + 1);
//     }
//     if (row == 0 || col == 0 || !color[row-1][col-1] || !color[row-1][col] || !color[row][col-1]) {
//         color[row][col] = true;
//         backtracking(row, col + 1);
//     }
// }

// int solution[][31] = {
//     {},
//     {},
//     {0, 0, 14, 50, 178, 634, 2258, 8042, 28642, 102010, 363314, 1293962, 4608514, 16413466, 58457426, 208199210 },
//     {0, 0, 0, 322, 2066, 13262, 85126, 546410, 3507314, 22512852, 144506294},
//     {0, 0, 0, 0, 23858, 275690, 385462, 36806846},
//     {0, 0, 0, 0, 0, 5735478, 119310334}
// };

// int main() {
//     cin >> n >> m;
//     if (n > m) swap(n, m);
//     if (n == 1) cout << (1 << m);
//     else cout << solution[n][m];

//     return 0;
// }

ostream& operator<<(ostream& os, __int128 x) {
    string s;
    do {
        s = char(x % 10 + '0') + s;
        x /= 10;
    } while (x);
    os << s;
    return os;
}

int main () {
    int n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);

    auto isGood = [&](int mask1, int mask2) {
        for (int i = 1; i < m; i++) {
            if (((mask1 & 3) == 0 || (mask1 & 3) == 3) && (mask2 & 3) == (mask1 & 3))
                return false;
            mask1 >>= 1;
            mask2 >>= 1;
        }
        return true;
    };

    int M = 1 << m;
    vector<vector<__int128>> lst(M), dp(n, vector<__int128>(M));
    for (int mask = 0; mask < M; mask++)
        for (int mask2 = 0; mask2 < M; mask2++)
            if (isGood(mask, mask2)) lst[mask].push_back(mask2);

    dp[0] = vector<__int128> (M, 1);
    for (int i = 1; i < n; i++)
        for (int mask = 0; mask < M; mask++)
            for (int v : lst[mask]) dp[i][mask] += dp[i-1][v];

    __int128 res = 0;
    for (auto x: dp[n-1]) res += x;
    cout << res;

    return 0;
}
