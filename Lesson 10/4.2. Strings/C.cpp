#include <iostream>
using namespace std;

int main()
{
    string e = "2.7182818284590452353602875";
    int n;
    cin >> n;
    if (n == 0)
        e = "3";
    else
    {
        if (e[n + 2] > '4')
            e[n + 1]++;
        e.erase(n + 2);
    }
    cout << e;
}