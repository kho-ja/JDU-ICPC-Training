#include <iostream>
#include <vector>
using namespace std;

int dp[1001][8][1001];

int inf = -2e9 + 9;

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 8; j++)
            for (int l = 0; l <= k; l++)
                dp[i][j][l] = inf;

    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];

    dp[0][0][0] = 0;

    auto setMax = [&](int row, int mask, int cnt, int add = 0) {
            if (cnt <= k) {
                dp[row + 1][mask][cnt] = max(dp[row + 1][mask][cnt], dp[row][mask][cnt] + add);
            }
        };

    for (int row = 0; row < n; row++) {
        for (int cnt = 0; cnt < k; cnt++) {
            if (dp[row][0][cnt] != inf) {
                setMax(row, 0, cnt, a[row][0]);
                setMax(row, 1, cnt + 1, a[row][1]);
                setMax(row, 2, cnt + 1, a[row][2]);
                setMax(row, 4, cnt + 1, a[row][0]);
                setMax(row, 5, cnt + 2, a[row][0] + a[row][1]);
                setMax(row, 6, cnt + 2, a[row][0] + a[row][2]);
                setMax(row, 7, cnt + 3, a[row][0] + a[row][1] + a[row][2]);
                setMax(row, 3, cnt + 2, a[row][1] + a[row][2]);
                setMax(row, 0, cnt + 1, a[row][0] + a[row][1] + a[row][2]);
            }
            if (dp[row][1][cnt] != inf) {
                setMax(row, 1, cnt, a[row][1]);
                setMax(row, 3, cnt + 1, a[row][2]);
                setMax(row, 5, cnt + 1, a[row][0]);
                setMax(row, 7, cnt + 2, a[row][0] + a[row][2]);
            }
            if (dp[row][2][cnt] != inf) {
                setMax(row, 2, cnt, a[row][2]);
                setMax(row, 3, cnt + 1, a[row][1]);
                setMax(row, 6, cnt + 1, a[row][0]);
                setMax(row, 7, cnt + 2, a[row][0] + a[row][1]);
            }
            if (dp[row][3][cnt] != inf) {
                setMax(row, 3, cnt, a[row][1] + a[row][2]);
                setMax(row, 7, cnt + 1, a[row][0]);
            }
            if (dp[row][4][cnt] != inf) {
                setMax(row, 4, cnt, a[row][0]);
                setMax(row, 5, cnt + 1, a[row][1]);
                setMax(row, 6, cnt + 1, a[row][2]);
                setMax(row, 7, cnt + 2, a[row][1] + a[row][2]);
            }
            if (dp[row][5][cnt] != inf) {
                setMax(row, 5, cnt, a[row][0] + a[row][1]);
                setMax(row, 7, cnt + 1, a[row][2]);
            }
            if (dp[row][6][cnt] != inf) {
                setMax(row, 6, cnt, a[row][0] + a[row][2]);
                setMax(row, 7, cnt + 1, a[row][1]);
            }
            if (dp[row][7][cnt] != inf) {
                setMax(row, 7, cnt, a[row][0] + a[row][1] + a[row][2]);
            }
        }
    }

    return 0;
}