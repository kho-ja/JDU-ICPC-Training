#include <iostream>
using namespace std;

int main()
{
    int n, mx = 0, cnt = 0;
    do
    {
        cin >> n;
        if (n > mx)
        {
            mx = n;
            cnt = 1;
        }
        else if (n == mx)
            cnt++;
    } while (n != 0);

    cout << cnt;
}