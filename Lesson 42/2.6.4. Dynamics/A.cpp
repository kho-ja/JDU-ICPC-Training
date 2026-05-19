#include <iostream>
#include <ostream>
using namespace std;
using ll = __int128;

ostream& operator<<(ostream& os, ll x) {
    string s = "";
    do {
        s = char('0' + x % 10) + s;
        x /= 10;
    } while (x);
    os << s;
    return os;
}

ll C(int n, int k) {
    ll res = 1;
    for (int i = 0; i < k; i++) res = res * (n - i) / (i + 1);
    return res;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    cout << 1LL * C(n+a, n) * C(n+b, n);
    return 0;
}
