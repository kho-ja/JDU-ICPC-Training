#include <iostream>
using namespace std;

int m;
long long n, a[15];
int best = 1e9;

void dfs(int i, long long sum, int cnt) {
    if (sum > n || cnt >= best) return;
    if (i == m) {
        if (sum == n) best = cnt;
        return;
    }

    dfs(i + 1, sum, cnt);
    dfs(i + 1, sum + a[i], cnt + 1);
    dfs(i + 1, sum + 2 * a[i], cnt + 2);
}

int main() {
    cin >> n >> m;

    long long total = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        total += 2LL * a[i];
    }

    if (total < n) {
        cout << -1;
        return 0;
    }

    dfs(0, 0, 0);
    cout << (best == (int)1e9 ? 0 : best);
    return 0;
}