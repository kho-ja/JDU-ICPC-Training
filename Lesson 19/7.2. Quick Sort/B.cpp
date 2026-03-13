#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, mn = INT_MAX, mx = 0;
    vector<int> a;
    a.reserve(100000);
    while (cin >> x) {
        a.push_back(x);
        mn = min(mn, x);
        mx = max(mx, x);
    }
    int n = a.size();
    if (n == 1 || mn == mx) {
        cout << "Yes\n";
        return 0;
    }
    if ((mx - mn) % (n - 1) != 0) {
        cout << "No\n";
        return 0;
    }
    int d = (mx - mn) / (n - 1), k = 0;
    vector<bool> used(n, false);
    for (int x : a) {
        if ((x - mn) % d) {
            cout << "No\n";
            return 0;
        }
        k = (x - mn) / d;
        if (k >= n || used[k]) {
            cout << "No\n";
            return 0;
        }
        used[k] = true;
    }
    cout << "Yes\n";
    return 0;
}