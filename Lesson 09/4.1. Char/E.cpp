#include <iostream>
using namespace std;

int main()
{
    char c;
    while (cin >> c)
        if (c != '4' && c != '7')
            cout << c;
}