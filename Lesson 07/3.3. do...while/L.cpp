#include <iostream>
using namespace std;

int main()
{
    int x = 100, prev, middle = 100, cnt = 0;
    do
    {
        prev = middle;
        middle = x;
        cin >> x;
        if (x != 0 && middle > prev && middle > x) cnt++;
    } while (x != 0);
    cout << cnt;
}