#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int M = max(n, m);

    for (int i = 1; i <= M; i++) {
        dp[i][i] = 1;
        dp[1][i] = i;
        dp[i][1] = i;
    }

    for (int j = 2; j <= M; j++) {
        for (int i = 2; i < j; i++) {
            int best = 1e9;

            for (int k = 1; k <= i / 2; k++) {
                int cur = dp[k][j] + dp[i - k][j];
                if (cur < best) best = cur;
            }

            for (int k = 1; k <= j / 2; k++) {
                int cur = dp[i][k] + dp[i][j - k];
                if (cur < best) best = cur;
            }

            dp[i][j] = best;
            dp[j][i] = best;
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}
