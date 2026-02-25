#include <iostream>
using namespace std;

long long F(int a) {
    long long r = 1;
    for (int i = 2; i <= a; i++) r *= i;
    return r;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << F(n) / (F(k) * F(n - k)) << "\n";
    return 0;
}