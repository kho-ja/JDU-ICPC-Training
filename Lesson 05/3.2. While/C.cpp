#include <iostream>
using namespace std;

int main()
{
    int n, i = 0, x;
    cin >> n;
    x = 1 << i;
    while (x <= n)
    {
        cout << x << " ";
        i++;
        x = 1 << i;
    }
}