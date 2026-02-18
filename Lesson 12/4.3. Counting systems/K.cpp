#include <iostream>
#include <string>
using namespace std;

int main() {
    char p;
    int n, d = 1;
    string  a, b;
    cin >> p >> n;

    while (n) {
        if (n % (d * 3) != 0) {
            if ((n - d) % (d * 3) == 0) {
                a += to_string(d) + " ";
                n -= d;
            }
            else {
                b += to_string(d) + " ";
                n += d;
            }
        }
        d *= 3;
    }

    if (p == 'L') swap(a, b);
    cout << "L:" << a << "\nR:" << b << "\n";
    return 0;
}