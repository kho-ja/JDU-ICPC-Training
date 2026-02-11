#include <iostream>
using namespace std;

int main()
{
    char c;
    int cnt = 0;
    while (cin >> c)
    {
        if (c == '6' || c == '0' || c == '9')
            cnt++;
        else if (c == '8')
            cnt += 2;
    }
    cout << cnt;
}