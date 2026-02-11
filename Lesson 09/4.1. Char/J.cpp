#include <iostream>
using namespace std;

int main()
{
    char c;
    int cnt = 0, mx=0;
    while (cin >> c)
    {
        if (c == '0') cnt++;
        else if (c == '1') cnt = 0;
        if (cnt > mx) mx = cnt;
    }
    cout << mx;
}