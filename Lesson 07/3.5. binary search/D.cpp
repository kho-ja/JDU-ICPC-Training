#include <iostream>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    if (x > y)
        swap(x, y);
    int L = x, R = 1e9 + 10;
    while (L != R)
    {
        int t = (L + R) / 2;
        if ((t / x + (t - x) / y) >= n)
            R = t;
        else
            L = t + 1;
    }
    cout << L;
}