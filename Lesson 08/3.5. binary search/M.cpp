#include <iostream>
using namespace std;

int main()
{
    long long L = 1, R = 1e9, S = 0, x, k = 0, m;

    while (L != R)
    {
        long long m = (L + R) / 2;
        x = m - S % m;
        cout << "run " << x << "\n";
        S += x;
        cin >> k;
        L = max(L, S / (k + 1) + 1);
        if (k != 0)
            R = min(R, S / k);
    }

    cout << "ensure " << L << "\n";
}