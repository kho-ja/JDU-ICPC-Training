#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 31 - __builtin_clz(n), x = n;
    for (int i = 0; i < l; i++) {
        n = ((n & 1) << l) | (n >> 1);
        x = max(x, n);
    }

    cout << x;
    return 0;
}