#include <iostream>
using namespace std;

int main()
{
    char c;
    int s = 0;
    while (cin >> c) if (c == '0') s++;
    cout << s << "\n";
}