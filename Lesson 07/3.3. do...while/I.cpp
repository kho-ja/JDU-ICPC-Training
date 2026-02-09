#include <iostream>
using namespace std;

int main()
{
    int x = 100, prev = 0, sum = 0;
    do
    {
        prev = x;
        cin >> x;
        sum += x;
    } while (x != 0 || prev != 0);
    cout << sum;
}