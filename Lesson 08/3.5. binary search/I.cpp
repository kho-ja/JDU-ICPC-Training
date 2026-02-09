#include <iostream>
using namespace std;

int main()
{
    int w, h, n;
    cin >> w >> h >> n;

    long long L = 0, R = max(1LL*min(w, h)*n, 1LL*max(w, h)), a;
    while (L != R)
    {
        long long a = (L + R) / 2;
        if (a/w*(a/h) >= n) {
            R = a;
        } else {
            L = a + 1;
        }
    }
    cout << L << endl;
}