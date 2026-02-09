#include <iostream>
using namespace std;

int main()
{
    int x = 100, prev, middle = 100, id = 0, pid = -1e9, mn = 1e9;
    do
    {
        prev = middle;
        middle = x;
        cin >> x;
        if (x != 0 && middle > prev && middle > x)
        {
            if (id - pid < mn)
            {
                mn = id - pid;
            }
            pid = id;
        }
        id++;
    } while (x != 0);
    cout << (mn == 1e9 ? 0 : mn);
}