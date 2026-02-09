#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    long long n, k, x, y, q;
    cin >> n >> k >> x >> y >> q;

    long long P = (n / k) * x + (n - n / k) * y;
    do
    {
        long long a;
        cin >> a;
        a %= P;

        long long L = 1, R = n;
        if (a == 0) L = n;

        while (L != R)
        {
            long long F = (L + R) / 2;
            if ((F / k) * x + (F - F / k) * y >= a) {
                R = F;
            } else {
                L = F + 1;
            }
        }
        cout << L << "\n";
    } while (--q);
}