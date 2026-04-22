#include <iostream>
using namespace std;

int main() {
    long long S, X, Y;
    cin >> S >> X >> Y;

    bool swapped = false;
    if (X < Y) {
        swap(X, Y);
        swapped = true;
    }

    long long start = S / X;

    for (long long i = 0; i <= Y; i++) {
        long long a = start - i;
        if (a < 0) break;

        long long rem = S - a * X;

        if (rem % Y == 0) {
            long long b = rem / Y;

            if (swapped) swap(a, b);
            cout << a << " " << b;
            return 0;
        }
    }

    cout << "-1 -1";
    return 0;
}