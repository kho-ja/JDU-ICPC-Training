#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& i : a) for (auto& j : i) cin >> j;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m / 2; j++) swap(a[i][j], a[i][m - 1 - j]);

    for (auto& i : a) {
        for (auto& j : i) cout << j << " ";
        cout << "\n";
    }
    return 0;
}