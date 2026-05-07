#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long x;
    while (m--) {
        cin >> x;
        cout << (binary_search(a.begin(), a.end(), x) ? "YES " : "NO ");
    }
    return 0;
}
