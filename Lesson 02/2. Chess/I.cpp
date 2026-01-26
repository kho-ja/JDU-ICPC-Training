#include <iostream>
using namespace std;

int main ()
{
    long long X, Y;
    cin >> X >> Y;
    cout << (X+Y==2 ? 0 : X == Y ? 2 : 1);
}