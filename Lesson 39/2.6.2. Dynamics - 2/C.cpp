#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, res = 0;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == '1') res = max(res, dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1);
        }
    }
    cout << res * res << '\n';
    return 0;
}
