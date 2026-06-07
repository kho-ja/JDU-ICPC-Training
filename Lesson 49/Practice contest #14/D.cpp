#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, mx = 0, mn = 2e9;
    long long res = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        res += x;
        if (mx < x) mx = x;
        if (mn > x) mn = x;
    }
    res -= mn + mx;
    cout << fixed << setprecision(6);
    cout << res / (n - 2);
    return 0;
}
