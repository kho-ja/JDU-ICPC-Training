#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
vector<int> b;

int main() {
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int L = n - 1; L >= 0; L--) {
        for (int R = L+1; R < n; R++) {
            int mn = 2e9;
            for (int mid = L; mid < R; mid++)
                mn = min(mn, dp[L][mid] + dp[mid + 1][R]);
            dp[L][R] = a[L] * b[R] + mn;
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
