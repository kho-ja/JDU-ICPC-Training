#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a != 0 || (b == 0 && c == 0)) cout << a;
    if (b != 0) {
        if (a != 0 && b > 0) cout << "+";
        if (b == -1) cout << "-";
        else if (b != 1) cout << b;
        cout << "x";
    }
    if (c != 0) {
        if (c > 0 && (a != 0 || b != 0)) cout << "+";
        if (c == -1) cout << '-';
        else if (c != 1) cout << c;
        cout << "y";
    }
}