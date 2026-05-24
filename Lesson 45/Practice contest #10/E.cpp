#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> grid(n+1);
    for (int i = 1; i <= n; i++) cin >> grid[i];
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if (c == 'L') {
            int a, b, k;
            cin >> a >> b >> k;
            auto it = grid.begin() + a;
            rotate(it, it + k, grid.begin() + b + 1);
        } else if (c == 'R') {
            int a, b, k;
            cin >> a >> b >> k;
            auto it = grid.begin() + a;
            rotate(it, grid.begin() + b - k + 1, grid.begin() + b + 1);
        } else if (c == 'P') {
            int x;
            cin >> x;
            cout << grid[x] << "\n";
        }
    }
    return 0;
}
