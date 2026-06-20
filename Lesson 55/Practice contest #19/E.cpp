#include <iostream>
using namespace std;
using ll = long long;

bool get(ll n) {
    if (n == 1) return false;
    ll r = 1, k, pc = 0;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            pc++;
            k = 0;
            while(n%p == 0) {
                ++k;
                n /= p;
            }
            r *= k + 1;
        }
    }
    if (n > 1) {
        pc ++;
        r *= 2;
    }
    return !(r % 2 == 1 || pc > 2 || (pc == 2 && r > 4));
}

int main() {
    ll n;
    cin >> n;
    cout << ("NY"[get(n)]);
    return 0;
}
