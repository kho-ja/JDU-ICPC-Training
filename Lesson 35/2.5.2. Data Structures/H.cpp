#include <iostream>
#include <map>
using namespace std;
using ll = long long;

map<ll, ll> mp;

ll get(ll n) {
    if (!mp.count(n)) {
        if (n < 4) mp[n] = n == 3;
        else mp[n] = get(n / 2) + get(n - n / 2);
    }
    return mp[n];
}

int main() {
    ll n;
    cin >> n;
    cout << get(n) << endl;
    return 0;
}
