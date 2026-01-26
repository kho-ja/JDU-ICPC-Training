#include <iostream>
using namespace std;

int main()
{
    int X, Y, X1, Y1;
    cin >> X >> Y;
    cin >> X1 >> Y1;
    if (X == X1 || Y == Y1) cout << "YES";
    else if (abs(X1 - X) == abs(Y1 - Y)) cout << "YES";
    else cout << "NO";
}