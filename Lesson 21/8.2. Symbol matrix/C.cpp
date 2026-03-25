#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<string> a(n);
    for (string& i : a) cin >> i;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int t = i > 0 ? i - 1 : i,
                b = i < n - 1 ? i + 1 : i,
                l = j > 0 ? j - 1 : j,
                r = j < m - 1 ? j + 1 : j;

            if (a[i][j] != '*' &&
                a[t][j] != '*' &&
                a[b][j] != '*' &&
                a[i][l] != '*' &&
                a[i][r] != '*')
                cnt++;
        }

    cout << cnt;
    return 0;
}