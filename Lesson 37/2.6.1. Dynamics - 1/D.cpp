#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = k - 1;
    for (int i = 2; i <= n; i++)
        dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
    cout << dp[n];

    return 0;
}
