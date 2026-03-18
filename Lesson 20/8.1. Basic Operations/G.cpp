#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(m, vector<int>(p));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < m; i++) for (int j = 0; j < p; j++) cin >> b[i][j];

    vector<vector<int>> c(n, vector<int>(p));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < m; k++)
                c[i][j] += a[i][k] * b[k][j];

    for (auto& i : c) {
        for (auto& j : i) cout << j << " ";
        cout << "\n";
    }
    return 0;
}