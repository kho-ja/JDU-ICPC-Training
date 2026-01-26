#include <iostream>
using namespace std;

int main() {
    int X, Y, X1, Y1;
    cin >> X >> Y;
    cin >> X1 >> Y1;

    if ((abs(X1 - X) <= 1) && (abs(Y1 - Y) <= 1)) cout << "YES";
    else cout << "NO";
}