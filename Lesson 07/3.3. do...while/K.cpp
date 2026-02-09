#include <iostream>
using namespace std;

int main()
{
    int x = 100, prev, cnto = 0, cntk = 0, mx = 0;
    do
    {
        prev = x;
        cin >> x;

        if (x == 0) break;
        
        if (x < prev) cnto++;
        else cnto = 1;
        if (x > prev) cntk++;
        else cntk = 1;

        if (cnto > mx) mx = cnto;
        if (cntk > mx) mx = cntk;
    } while (x != 0);
    cout << mx;
}