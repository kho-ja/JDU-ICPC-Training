#include <iostream>
using namespace std;

int main()
{
    int n, mx = 0, mxprev = 0;
    do
    {
        cin >> n;
        if (n > mx)
        {
            mxprev = mx;
            mx = n;
        }
        else if (n > mxprev)
            mxprev = n;
    } while (n != 0);
    cout << mxprev;
}