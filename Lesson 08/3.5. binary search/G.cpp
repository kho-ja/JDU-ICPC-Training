#include <iostream>
using namespace std;

int main()
{
    long long a, k, b, m, x;
    cin >> a >> k >> b >> m >> x;

    long long L = (x + a + b - 1) / (a + b), R = 2 * L - 1;
    while (L != R)
    {
        long long D = (L + R) / 2;
        if (((D - D / k) * a + (D - D / m) * b) >= x) {
            R = D;
        } else {
            L = D + 1;
        }
    }
    cout << L << endl;
}