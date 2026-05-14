#include <iostream>
using namespace std;
using ll = long long;

int main () {
    ll n, a, d1 = 0, d2 = 0, d3 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        d3 += a * d2;
        d2 += a * d1;
        d1 += a;
    }

    cout << d3 << '\n';
    return 0;
}
