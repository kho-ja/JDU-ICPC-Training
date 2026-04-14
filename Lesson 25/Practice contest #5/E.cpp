#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, mn = 2e9;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int l = 0, r = a.size() - 1; l < r; l++, r--)
        mn = min(mn, a[r] + a[l]);

    cout << mn << '\n';
    return 0;
}
