#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K, M;
    cin >> K >> M;
    int mod = 1000000009;
    vector<vector<int>> dp(K + 1, vector<int>(K + 1));
    for (int n = 0; n <= K; n++)
        for (int k = 0; k <= n && k <= M; k++)
            dp[n][k] = k == 0 ? 1 : (dp[n - 1][k - 1] + dp[n - 1][k]) % mod;

    cout << (dp[K][M] - dp[K][M - 1] + mod) % mod;
    return 0;
}