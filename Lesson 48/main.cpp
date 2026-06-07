#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const ll mod = 1e9 + 7;

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

ll fibonacci(ll n) {
    Matrix init(1, 2);
    init[0][0] = 0; // F0
    init[0][1] = 1; // F1

    Matrix T(2, 2);
    T[0][0] = 0;
    T[0][1] = 1;
    T[1][0] = 1;
    T[1][1] = 1;

    Matrix res = init * binpow(T, n);
    return res[0][0];
}

int main() {
    ll n;
    cin >> n;
    cout << fibonacci(n) << '\n';
    return 0;
}