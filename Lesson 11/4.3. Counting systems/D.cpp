#include <iostream>
using namespace std;

int main()
{
    int n, x = 0;
    cin >> n;
    do
    {
        x = (x<<1)|(n&1);
        n >>= 1;
    } while (n > 0);
    cout << x;
}