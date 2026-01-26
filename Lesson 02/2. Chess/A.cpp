// #include <iostream>
// using namespace std;

// int main()
// {
//     int X, Y, X1, Y1;
//     cin >> X >> Y;
//     cin >> X1 >> Y1;
//     if (X1 == X || Y1 == Y) cout << "YES";
//     else cout << "NO";
// }

#include <iostream>
using namespace std;

int main() {
    int X, Y, X1, Y1;
    cin >> X >> Y;
    cin >> X1 >> Y1;

    cout << (X1 == X || Y1 == Y ? "YES" : "NO");
}