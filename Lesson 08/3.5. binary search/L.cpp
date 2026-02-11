#include <iostream>
using namespace std;

int main()
{
    long long n, k, s, L = 1, R, tmp, x1=0, s2, s3;
    cin >> n;
    R = n;

    k = n;
    cout << "? " << k << "\n";
    cin >> s;
    s = k * (k + 1) / 2 - s;

    s3 = s;

    while (true)
    {
        k = (L + R) / 2;
        cout << "? " << k << "\n";
        cin >> s;
        s = k * (k + 1) / 2 - s;
        if (s == 0)
            L = k + 1;
        else if (s == s3)
            R = k - 1;
        else
            break;
    }

    tmp = s;
    if (s < n)
    {
        cout << "? " << tmp - 1 << "\n";
        cin >> s;
        s = tmp * (tmp - 1) / 2 - s;
        if (s == 0)
            x1 = tmp;
    }

    s = tmp;
    if (x1 != 0)
    {
        L = k + 1;
        while (true)
        {
            k = (L + R) / 2;
            cout << "? " << k << "\n";
            cin >> s;
            s = k * (k + 1) / 2 - s;
            if (s == x1)
                L = k + 1;
            else if (s == s3)
                R = k - 1;
            else
            {
                s2 = s;
                break;
            }
        }
    }
    else
    {
        s2 = s;
        R = k - 1;
        while (true)
        {
            k = (L + R) / 2;
            cout << "? " << k << "\n";
            cin >> s;
            s = k * (k + 1) / 2 - s;
            if (s == 0)
                L = k + 1;
            else if (s == s2)
                R = k - 1;
            else
            {
                x1 = s;
                break;
            }
        }
    }

    cout << "! " << x1 << " " << s2 - x1 << " " << s3 - s2 << "\n";
}