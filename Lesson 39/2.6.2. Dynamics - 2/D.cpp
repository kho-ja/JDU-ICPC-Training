#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, res = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int L = n - 1; L >= 0; L--) {
        dp[L][L] = a[L];
        for (int R = L + 1; R < n; R++)
            dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
    }
    cout << (dp[0][n-1] < 0 ? 2 : dp[0][n-1] > 0 ? 1 : 0) << '\n';
    return 0;
}
