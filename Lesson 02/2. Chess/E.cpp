// #include <iostream>
// using namespace std;

// int main() {
//     int X, Y, X1, Y1;
//     cin >> X >> Y;
//     cin >> X1 >> Y1;
//     if (abs(X1 - X) == 2 && abs(Y1 - Y) == 1) cout << "YES";
//     else if (abs(X1 - X) == 1 && abs(Y1 - Y) == 2) cout << "YES";
//     else cout << "NO";
// }

#include <iostream>
using namespace std;

int main() {
    int X, Y, X1, Y1;
    cin >> X >> Y >> X1 >> Y1;
    cout << (abs(X - X1) * abs(Y - Y1) == 2 ? "YES" : "NO");
}