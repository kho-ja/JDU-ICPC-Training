#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> dp(n);
    for (auto &x: a) cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    dp[0] = 2e9;
    dp[1] = a[1].second;
    for (int i = 2; i < n; i++)
        dp[i] = a[i].second + min(dp[i - 1], dp[i - 2]);
    cout << dp[n - 1];

    return 0;
}
