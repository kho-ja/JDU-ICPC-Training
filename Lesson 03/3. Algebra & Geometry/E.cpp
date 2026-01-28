#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1, y1, x2, y2, xA, yA;
    cin >> x1 >> y1 >> x2 >> y2 >> xA >> yA;

    if (y1 == y2)
        cout << xA << " " << (2 * y1 - yA);
    else if (x1 == x2)
        cout << (2 * x1 - xA) << " " << yA;
}