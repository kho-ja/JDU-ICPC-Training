#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, x, y;
    cin >> a >> b;

    double d = a*a - 4*b;
    x = (a - sqrt(d)) / 2;
    y = a - x;

    cout << x << ' ' << y << '\n';
}