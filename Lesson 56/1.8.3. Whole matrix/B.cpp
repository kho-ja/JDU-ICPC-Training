#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, cnt;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m, true));
    cin >> cnt;
    while (cnt--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++)
            for (int j = y1; j < y2; j++)
                a[i][j] = false;
    }
    long long res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res += a[i][j];
    cout << res;
    return 0;
}
