#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[0] = dp[1] = 1;
    if (n > 1) dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]);
    cout << dp[n];

    return 0;
}
