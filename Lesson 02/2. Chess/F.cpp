#include <iostream>
using namespace std;

int main()
{
    int X, Y, X1, Y1;
    cin >> X >> Y;
    cin >> X1 >> Y1;

    if (Y == 1) cout << "NO";
    else if (X == X1 && Y1 - Y == 1)
        cout << "YES";
    else if (X == X1 && Y == 2 && Y1 == 4)
        cout << "YES";
    else
        cout << "NO";
}
