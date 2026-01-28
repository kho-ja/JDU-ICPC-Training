// #include <iostream>
// #include <cmath>
// #include <iomanip>
// using namespace std;

// int main() {
//     double x, y, X, Y;
//     cin >> x >> y >> X >> Y;
//     cout << fixed << setprecision(6) << hypot(X - x, Y - y);
// }

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout.precision(5);
    cout << fixed;
    cout << hypot(x2 - x1, y2 - y1);
}