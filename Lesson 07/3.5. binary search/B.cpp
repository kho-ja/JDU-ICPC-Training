#include <iostream>
using namespace std;

int main() {
    long long a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    long long n = min(a1, a2) + min(a3, a4);
    
    long long L = 0, R = 1.5e9;
    while (L != R) {
        long long M = (L + R + 1) / 2;
        if (M * M <= n) L = M;
        else R = M - 1;
    }
    cout << L;
}