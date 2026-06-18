#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, mod = 1e6;
    cin >> k;

    vector<int> dp(1e5+1);
    dp[10] = dp[11] = dp[12] = 2;
    for (int i = 20; i <= k; i++) {
        dp[i] = (dp[i - 10] + dp[i - 11] + dp[i - 12]) % mod;
    }

    cout << dp[k];
    return 0;
}
