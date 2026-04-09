#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

// safe power (with limit)
__int128 power(int64 a, int b, int64 limit) {
    __int128 res = 1;
    for (int i = 0; i < b; i++) {
        res *= a;
        if (res > limit) return res;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int64 M;
    cin >> N >> M;

    while (N--) {
        int64 x;
        cin >> x;

        int64 best = 1; // minimal power
        int64 bestDist = abs(x - 1);

        for (int b = 2; b <= 60; b++) {
            double approx = pow((double)x, 1.0 / b);
            int64 a = (int64)approx;

            for (int64 da = -1; da <= 1; da++) {
                int64 base = a + da;
                if (base < 1) continue;

                __int128 val = power(base, b, M);
                if (val > M) continue;

                int64 v = (int64)val;
                int64 dist = abs(x - v);

                if (dist < bestDist || (dist == bestDist && v < best)) {
                    bestDist = dist;
                    best = v;
                }
            }
        }

        cout << best << "\n";
    }

    return 0;
}