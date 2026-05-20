#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(n, vector<int>(n,0)));
    vector<string> a(k+1);

    for(auto &s : a) cin >> s;

    dp[0][0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (a[x][y] == '0') {
                    int t = x > 0 ? dp[i-1][x-1][y] : 0;
                    int b = x < n - 1 ? dp[i-1][x+1][y] : 0;
                    int l = y > 0 ? dp[i-1][x][y-1] : 0;
                    int r = y < n - 1 ? dp[i-1][x][y+1] : 0;
                    dp[i][x][y] = t + b + l + r;
                }
            }
        }
    }

    cout << dp[k][n-1][n-1];
    return 0;
}
