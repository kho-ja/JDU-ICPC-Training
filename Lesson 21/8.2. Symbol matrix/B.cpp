#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, cnt = 0;
    char x;
    cin >> n >> m;
    vector<string> a(n);
    for (string& i : a) cin >> i;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (a[i][j] == x) cnt++;
        }

    cout << cnt;
    return 0;
}