#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> rowsums(n), colsums(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            rowsums[i] += a[i][j];
            colsums[j] += a[i][j];
        }
    };

    for (const auto& sum : rowsums) cout << sum << " ";
    cout << "\n";
    for (const auto& sum : colsums) cout << sum << " ";
    cout << "\n";
    cout << "\n";

    for (const auto& i : a) {
        for (const auto& j : i) cout << j << " ";
        cout << "\n";
    }
    return 0;
}