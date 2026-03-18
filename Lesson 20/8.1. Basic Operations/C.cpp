#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto& i : a) for (auto& j : i) cin >> j;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1 - i; j++) swap(a[i][j], a[n - j - 1][n - i - 1]);

    for (auto& i : a) {
        for (auto& j : i) cout << j << " ";
        cout << "\n";
    }
    return 0;
}