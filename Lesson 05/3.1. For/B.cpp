#include <iostream>
using namespace std;

int main() {
    int n, x, mn, mx;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (mn < x) mn = x;
        if (mx > x) mx = x;
    }
    cout << mx << " " << mn;
}