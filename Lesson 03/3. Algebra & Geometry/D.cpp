#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, y, r, X, Y, R;
    cin >> x >> y >> r >> X >> Y >> R;

    double d = hypot(X - x, Y - y);
    cout << (d <= R + r && d >= abs(R - r) ? "YES" : "NO");
}