#include <iostream>
#include <map>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, c;
    cin >> n;
    long long res = 1LL * n * (n - 1) * (n - 2) / 6;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        c = gcd(abs(a), abs(b));
        if (c != 0) {
            a /= c;
            b /= c;
        }
        if (a < 0) {
            a = -a;
            b = -b;
        }
        if (a == 0 && b < 0) b = 1;
        mp[{a, b}]++;
    }

    for (auto& p : mp) {
        int x = p.second;
        res -= 1LL * x * (x - 1) * (x - 2) / 6 + 1LL * x * (x - 1) / 2 * (n - x);
    }
    cout << res % 1000000007 << "\n";
    return 0;
}
