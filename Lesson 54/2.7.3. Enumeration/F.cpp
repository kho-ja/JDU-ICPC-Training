#include <iostream>
using namespace std;

int C (int n, int k) {
    int r = 1;
    for (int i = 0; i < k; ++i) r = r * (n - i) / (i + 1);
    return r;
}

int main () {
    int n, k, m;
    cin >> n >> k >> m;
    for (int h = 1, x; h <= n && k > 0; h++) {
        x = C(n-h, k-1);
        if(x >= m) {
            cout << char(h+96);
            --k;
        }
        else m -= x;
    }
    return 0;
}
