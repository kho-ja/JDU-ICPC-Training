#include <iostream>
using namespace std;

int main()
{
    int x, y, a = 0, b = 1, c;
    cin >> x >> y;
    while (y)
        swap(x %= y, y);

    while (x--)
    {
        c = (a+ b) % 1000000000;
        a = b;
        b = c;
    }
    cout << a;
}