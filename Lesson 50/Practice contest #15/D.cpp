#include <iostream>
#include <numeric>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    if (N == 0) {
        cout << 0;
        return 0;
    }
    if (M == 0) {
        cout << "INF";
        return 0;
    }
    long long gcdnums = gcd(N, M);
    if (gcdnums != 1) {
        N /= gcdnums;
        M /= gcdnums;
    }

    if (N > 0 && M > 0) {
        long long wholepart = N / M;
        if (wholepart != 0) cout << wholepart;
        if (wholepart != 0 && N % M != 0) cout << "+";
        if (N % M != 0) cout << N - wholepart * M << "/" << M;
    }
    else if ((N < 0) ^ (M < 0)) {
        cout << '-';
        if (N < 0) N = -N;
        if (M < 0) M = -M;
        long long wholepart = (N + M - 1) / M;
        if (wholepart) cout << wholepart;
        if (wholepart && N % M != 0) cout << "+";
        if (N % M != 0) cout << wholepart * M - N << "/" << M;
    }
    else if ((N < 0) && (M < 0)) {
        N = -N;
        M = -M;
        long long wholepart = N / M;
        if (wholepart != 0) cout << wholepart;
        if (wholepart != 0 && N % M != 0) cout << "+";
        if (N % M != 0) cout << N - wholepart * M << "/" << M;
    }
    return 0;
}
