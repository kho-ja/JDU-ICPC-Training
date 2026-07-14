#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    ll sum = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double av = double(sum) / n, mx = -av, mn = av, loss = 0;
    for (auto x:a) {
        ll diff = (x - av);
        ll num = (diff % k);
        loss += diff;
        if (num > mx) mx = num;
        if (num < mn) mn = num;
        printf("sum: %lld, k: %lld, av: %f, x: %d, loss: %f, num: %lld, mx: %f, mn: %f\n", sum, k, av, x, loss, num, mx, mn);
    }
    cout << mx - mn + loss;
    return 0;
}
