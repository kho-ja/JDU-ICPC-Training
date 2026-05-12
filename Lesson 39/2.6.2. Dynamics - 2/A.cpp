#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n), dp(n);
    for (auto& x : v) cin >> x;
    if (n > 1)
        dp[1] = abs(v[0] - v[1]);
    for (int i = 2; i < n; i++)
        dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]), dp[i - 2] + 3 * abs(v[i] - v[i - 2]));
    cout << dp[n - 1] << endl;
    return 0;
}
