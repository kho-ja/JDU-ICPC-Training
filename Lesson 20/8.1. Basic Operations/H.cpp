#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, n;
    cin >> x >> y >> n;
    vector<vector<int>> a(x, vector<int>(y));
    n %= 4;
    for (auto& i : a) for (auto& j : i) cin >> j;

    while (n) {
        vector<vector<int>> b(y, vector<int>(x));
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                b[j][x - 1 - i] = a[i][j];
        swap(x, y);
        a = move(b);
        n--;
    }

    for (auto& i : a) {
        for (auto& j : i) cout << j << " ";
        cout << "\n";
    }
    return 0;
}