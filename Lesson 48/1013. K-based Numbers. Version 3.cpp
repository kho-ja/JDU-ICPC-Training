#include <iostream>
#include <vector>
using namespace std;

using ll = __int128;

ll mod = 1e9 + 7;

struct Matrix {
    vector<vector<ll>> a;
    int n, m;

    Matrix(int n, int m) : n(n), m(m) {
        a.assign(n, vector<ll>(m, 0));
    }

    vector<ll>& operator[](int i) {
        return a[i];
    }

    const vector<ll>& operator[](int i) const {
        return a[i];
    }

    friend Matrix operator*(const Matrix& A, const Matrix& B) {
        Matrix C(A.n, B.m);

        for (int i = 0; i < A.n; i++) {
            for (int k = 0; k < A.m; k++) {
                for (int j = 0; j < B.m; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }

        return C;
    }
};

Matrix binpow(Matrix A, ll p) {
    Matrix R(A.n, A.n);

    for (int i = 0; i < A.n; i++) {
        R[i][i] = 1;
    }

    while (p > 0) {
        if (p & 1) {
            R = R * A;
        }
        A = A * A;
        p >>= 1;
    }

    return R;
}

long long fibonacci(ll n, ll k) {
    Matrix init(1, 2);
    init[0][0] = 0; // F0
    init[0][1] = k - 1; // F1

    Matrix T(2, 2);
    T[0][0] = 0;
    T[0][1] = k - 1;
    T[1][0] = 1;
    T[1][1] = k - 1;

    Matrix res = init * binpow(T, n - 1);
    return (res[0][0] + res[0][1]) % mod;
}

ostream& operator<<(ostream& os, ll x) {
    string s;
    do {
        s = char('0' + x % 10) + s;
        x /= 10;
    } while (x > 0);
    os << s;
    return os;
}

int main() {
    long long n, k, m;
    cin >> n >> k >> m;
    mod = m;
    cout << fibonacci(n, k) << '\n';
    return 0;
}