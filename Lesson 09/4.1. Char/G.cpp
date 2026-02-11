#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    cout << c;
    while (cin >> c)
    {
        cout << char(35);
        cout << c;
    }
}