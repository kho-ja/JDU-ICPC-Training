#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(n);
    vector<vector<int>> in(p+1), out(p+1);

    long long now = 0, overall = 0;

    for (int i = 0, c, d; i < n; i++) {
        cin >> a[i] >> b[i] >> c >> d;
        if (a[i] < b[i]) {
            overall += 1LL * b[i] * (d - c);
            continue;
        }
        in[c].push_back(i);
        out[d].push_back(i);
    }

    multiset<int> sit;
    multiset<int, greater<>> stand;
    for (int i = 1; i<=p; i++) {
        for (int x:out[i]) {
            int v = a[x] - b[x];
            auto it = stand.find(v);
            if (it != stand.end()) {
                stand.erase(it);
                now -= b[x];
            }
            else {
                sit.erase(sit.find(v));
                now -= a[x];
            }
        }
        for (int x: in[i]) {
            stand.insert(a[x] - b[x]);
            now += b[x];
        }
        while (sit.size() < m && !stand.empty()) {
            now += *stand.begin();
            sit.insert(*stand.begin());
            stand.erase(stand.begin());
        }
        if (!stand.empty())
            while (*sit.begin() < *stand.begin()) {
                now -= *sit.begin();
                stand.insert(*sit.begin());
                sit.erase(sit.begin());
                now += *stand.begin();
                sit.insert(*stand.begin());
                stand.erase(stand.begin());
            }
        overall += now;
    }
    cout << overall;
    return 0;
}
