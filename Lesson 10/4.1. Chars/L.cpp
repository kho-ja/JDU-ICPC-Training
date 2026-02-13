#include <iostream>
using namespace std;

int main()
{
    int vcnt = 0, ccnt = 0, res = 0;
    char c;
    while (cin >> c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
        {
            ccnt = 0;
            if (++vcnt == 3)
            {
                res++;
                vcnt = 1;
            }
        }
        else
        {
            vcnt = 0;
            if (++ccnt == 3)
            {
                res++;
                ccnt = 1;
            }
        }
    }
    cout << res;
}