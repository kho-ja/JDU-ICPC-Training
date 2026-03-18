#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto& i : a) for (auto& j : i) cin >> j;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) swap(a[i][j], a[j][i]);

    for (auto& i : a) for (auto& j : i) cout << j << " ";
    return 0;
}