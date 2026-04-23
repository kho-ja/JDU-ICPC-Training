#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inv_count(vector<int>& a, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) >> 1;
    int res = inv_count(a, l, m) + inv_count(a, m, r);
    for (int x = l, y = m; x < m; ++x) {
        while (y < r && a[y] < a[x]) y++;
        res += y - m;
    }
    inplace_merge(a.begin() + l, a.begin() + m, a.begin() + r);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, cnt = 0;
    cin >> n >> k;
    vector<int> a(n);

    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cnt += inv_count(a, 0, n);
    }
    cout << cnt;
    return 0;
}