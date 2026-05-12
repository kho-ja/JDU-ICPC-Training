#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, b, m;
    cin >> n;
    vector<int> v(n), dp(n, 1), tmp;
    cin >> v[0] >> k >> b >> m;
    for (int i = 1; i < n; i++) v[i] = (k * v[i-1] + b) % m;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tmp.begin(), tmp.end(), v[i]);
        dp[i] = it - tmp.begin();
        if (it == tmp.end())
            tmp.push_back(v[i]);
        else
            *it = v[i];
    }

    int val = tmp.back() + 1;
    int ans = tmp.size();

    for (int i = n - 1; i >= 0; i--) {
        if (v[i] < val && dp[i] == ans - 1) {
            val = v[i];
            tmp[--ans] = v[i];
        }
    }

    for (int &x : tmp) cout << x << ' ';
    return 0;
}
