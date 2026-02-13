#include <iostream>
using namespace std;

int main()
{
    char x1, y1,dash, x2, y2;
    if (cin >> x1 >> y1 >> dash >> x2 >> y2 && dash == '-' && x1 >= 'A' && x1 <= 'H' && x2 >= 'A' && x2 <= 'H' && y1 >= '1' && y1 <= '8' && y2 >= '1' && y2 <= '8')
    {
        if (abs(x1 - x2) * abs(y1 - y2) == 2)
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "ERROR";
}