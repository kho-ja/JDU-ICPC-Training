#include <iostream>
using namespace std;

int main()
{
    int x, L = 1, R = 1e9;
    do
    {
        int mid = (L + R) / 2;
        cout << "? " << mid << "\n";
        cin >> x;
        if (x == mid)
        {
            L = mid + 1;
        }
        else
        {
            R = mid - x;
        }
    } while (L != R);

    cout << "! " << L << "\n";
}