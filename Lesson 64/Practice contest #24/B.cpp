#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
using ll = long long;

ll C(int n, int k) {
    ll res = 1;
    for (int i = 0; i < k; i++) res = res * (n - i) / (i + 1);
    return res;
}

ll F(int n, int k) {
    if (C(n, k) % 2 == 1) return k;
    return 0;
}

int main() {
    ll n;
    cin >> n;
    ll S = 0;
    for (int k = 1; k <= n; k++) S+=F(n, k);
//    for (int i = 1; i < 10; i++) {
//        for (int j = 1; j <= i; j++) {
//            cout << format("i: {}, j: {}, Cnk: {}\n", i, j, C(i, j));
//        }
//    }
    cout << S;
    return 0;
}
