#include <iostream>
using namespace std;

int main ()
{
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;
    cout << (abs(X1 + X2) % 2 == abs(Y1 + Y2) % 2 ? "YES" : "NO");
}