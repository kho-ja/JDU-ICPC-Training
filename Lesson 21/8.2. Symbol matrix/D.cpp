#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 0;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'C') cnt++;
        }
    }

    cnt /= 2;
    vector<vector<int>> b(n, vector<int>(n, 2));
    for (int i = 0; i < n && cnt > 0; i++) {
        for (int j = 0; j < n && cnt > 0; j++) {
            if (a[i][j] == 'C') {
                cnt--;
            }
            b[i][j] = 1;
        }
    }

    for (const auto& i : b) {
        for (const auto& j : i) cout << j;
        cout << "\n";
    }
    return 0;
}