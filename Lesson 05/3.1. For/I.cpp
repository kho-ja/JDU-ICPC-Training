#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool first = true;

    for (int x = -100; x <= 100; ++x) {
        long long val = a*1LL*x*x*x + b*1LL*x*x + c*1LL*x + d;
        if (val == 0) {
            if (!first) cout << " ";
            cout << x;
            first = false;
        }
    }
}