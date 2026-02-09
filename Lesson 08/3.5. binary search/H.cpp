#include <iostream>
using namespace std;

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < 0)
    {
        a = -a;
        b = -b;
        c = -c;
        d = -d;
    }

    double L = -1e9, R = 1e8, x, eps = 1e-6;
    while (R - L > eps)
    {
        x = (L + R) / 2;
        if (a * x * x * x + b * x * x + c * x + d >= 0)
            R = x;
        else
            L = x;
    }
    cout << fixed << L;
}