#include <iostream>
using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    c = n - (a + b);

    for (int i = 1; i <= a; i++)
        cout << char(i % 2 + 'A');

    for (int i = 1; i <= b; i++)
        cout << char(i % 2 + 'a');

    for (int i = 1; i <= c; i++)
        cout << i % 2;

    return 0;
}