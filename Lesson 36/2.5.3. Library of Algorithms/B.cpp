#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m;
    cin >> m;
    vector<int> price(1001, 1001), p(1001);
    for (int i = 0, v, pr; i < m; i++) {
        cin >> v >> pr;
        if (price[v] > pr)
            price[v] = pr;
    }
    p[1000] = price[1000];
    for (int i = 999; i >= 0; i--)
        p[i] = min(p[i+1], price[i]);

    int overall = 0;
    for (int &x: a)
        overall += p[x];

    cout << overall;
    return 0;
}
