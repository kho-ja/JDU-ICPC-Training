#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main () {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    cin >> k;

    ll sum = 0;
    vector<vector<ll>> dp(n, vector<ll>(k + 1, 0));
    for (int L = n - 1; L >= 0; L--) {
        sum += a[L];
        for (int t = 1; t <= k; t++) {
            if (L + t >= n)
                dp[L][t] = sum;
            else if (t == 1)
                dp[L][t] = sum - dp[L + 1][1];
            else
                dp[L][t] = max(sum - dp[L + t][t], dp[L][t - 1]);
        }
    }

    cout << dp[0][k] << '\n';

    return 0;
}
