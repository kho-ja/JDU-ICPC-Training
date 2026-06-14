#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

int get(ll num) {
    int res = 0;
    for (ll i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            res++;
            if (i != num / i) res++;
        }
    }
    return res;
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll g = gcd(n, m);
    auto gg = get(g);

    cout << gg;
    return 0;
}
