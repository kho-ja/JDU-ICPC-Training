#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long modPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    long long N;
    cin >> N;

    if (N == 2) {
        cout << 1;
        return 0;
    }

    if (N % 3 == 0) {
        cout << modPow(3, N / 3);
    }
    else if (N % 3 == 1) {
        cout << (modPow(3, N / 3 - 1) * 4) % MOD;
    }
    else {
        cout << (modPow(3, N / 3) * 2) % MOD;
    }

    return 0;
}