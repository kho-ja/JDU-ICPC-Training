#include <iostream>
using namespace std;

int main()
{
    int n, cnt = 0, prev = -1;
    do
    {
        cin >> n;
        if (prev != -1 && prev < n)
            cnt++;
        prev = n;
    } while (n != 0);
    cout << cnt;
}