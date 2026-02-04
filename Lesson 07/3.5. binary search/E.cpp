#include <iostream>
using namespace std;

int main()
{
    long long n, a, b, w, h, d;
    cin >> n >> a >> b >> w >> h;
    long long L = 0, R = 1e18;
    while (L != R)
    {
        d = (L + R + 1) / 2;
        if (max((h / (a + 2 * d)) * (w / (b + 2 * d)), (h / (b + 2 * d)) * (w / (a + 2 * d))) >= n)
            L = d;
        else
            R = d - 1;
    }
    cout << L;
}