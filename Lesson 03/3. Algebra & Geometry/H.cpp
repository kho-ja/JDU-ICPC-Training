#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed;

    if (a == 0)
    {
        if (b == 0)
            cout << (c == 0 ? "-1" : "0");
        else
            cout << "1\n"
                 << -c / b;
    }
    else
    {
        double D = b * b - 4 * a * c;
        if (D < 0)
            cout << "0";
        else if (D == 0)
            cout << "1\n"
                 << -b / (2 * a);
        else
            cout << "2\n"
                 << (-b - sqrt(D)) / (2 * a) << "\n"
                 << (-b + sqrt(D)) / (2 * a);
    }
}