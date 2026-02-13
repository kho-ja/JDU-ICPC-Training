#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char a, b, c, i;
    cin >> a >> i >> b >> c >> c;

    if (i == '+')
        cout << (a == 'x'
                     ? c - b
                 : b == 'x'
                     ? c - a
                     : (a + b - 2 * '0'));
    else
        cout << (a == 'x'
                     ? c + b - 2 * '0'
                 : b == 'x'
                     ? a - c
                     : a - b);
}