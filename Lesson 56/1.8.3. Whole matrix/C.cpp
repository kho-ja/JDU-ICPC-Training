#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> a[j][k];
            }
        }

        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < m - 1; k++) {
                if (a[j][k] == a[j+1][k] && a[j][k+1] == a[j+1][k+1] && a[j][k+1] == a[j][k]) {
                    cout << "NO\n";
                    goto end;
                } 
            }
        }
        cout << "YES\n";
        end:;
    }
    return 0;
}
