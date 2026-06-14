#include <iostream>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    int mx = N * (N - 1) / 2;
    int k = min(mx - C, C);
    if (C > mx) cout << 0;
    if (mx / 2 == k) cout << (2 * k) % 1000000007;
    else cout << (k * 2 + 1) % 1000000007;
    return 0;
}
