#include <iostream>
using namespace std;

int main()
{
    int n, i = 1, x;
    cin >> n;
    x = i * i;
    while (x <= n)
    {
        cout << x << " ";
        i++;
        x = i * i;
    }
}