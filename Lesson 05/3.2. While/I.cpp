#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int x, mn = 10001, mx = -10001, i = 0;
    while (cin >> x)
    {
        i++;
        if (i % 2 == 1 && x < mn)
            mn = x;
        if (i % 2 == 0 && x > mx)
            mx = x;
    }
    cout << mx + mn;
}