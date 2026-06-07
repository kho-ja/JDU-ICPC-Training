#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B, C, A1, B1, C1;
        cin >> A >> B >> C >> A1 >> B1 >> C1;

        bool invalid1 = (A == 0 && B == 0 && C != 0);
        bool invalid2 = (A1 == 0 && B1 == 0 && C1 != 0);
        bool trivial1 = (A == 0 && B == 0 && C == 0);
        bool trivial2 = (A1 == 0 && B1 == 0 && C1 == 0);

        if (invalid1 || invalid2) {
            cout << 0;
            continue;
        }

        if (trivial1 || trivial2) {
            cout << -1;
            continue;
        }

        bool same = (1LL * A * B1 == 1LL * B * A1) &&
                    (1LL * A * C1 == 1LL * C * A1) &&
                    (1LL * B * C1 == 1LL * C * B1);

        if (same) {
            cout << -1;
        } else if (1LL * A * B1 == 1LL * B * A1) {
            cout << 0;
        } else {
            cout << 1;
        }

        if (T) cout << endl;
    }
    return 0;
}
