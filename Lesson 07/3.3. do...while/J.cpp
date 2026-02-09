#include <iostream>
using namespace std;

int main()
{
    int x = 100, prev, cnt = 0, mx = 0;
    do
    {
        prev = x;
        cin >> x;
        if (x == prev) cnt++;
        else cnt = 1;
        if (cnt > mx) mx = cnt;
    } while (x != 0);
    cout << mx;
}