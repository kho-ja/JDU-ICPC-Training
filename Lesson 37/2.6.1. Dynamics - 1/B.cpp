#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), dp(n);
    for (int &x: a) cin >> x;
    sort(a.begin(), a.end());
    dp[1] = a[1] - a[0];
    dp[0] = 2e9;
    for (int i = 2; i < n; i++)
        dp[i] = a[i] - a[i - 1] + min(dp[i - 1], dp[i - 2]);
    cout << dp[n - 1];
    return 0;
}
