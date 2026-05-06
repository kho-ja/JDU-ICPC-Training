#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) cin >> x >> y;
    sort(a.rbegin(), a.rend());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k - 1; i++) pq.push(a[i].second);

    long long res = 0;
    for (int i = k - 1; i < n; i++) {
        pq.push(a[i].second);
        res = max(res, (long long)a[i].first * pq.top());
        pq.pop();
    }
    cout << res << '\n';
    return 0;
}
