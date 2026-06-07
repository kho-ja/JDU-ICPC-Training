#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double n;
    cin >> n;
    cout << fixed << setprecision(5);
    cout << n + 273.15 << "\n" << n * 1.80 + 32.00;
    return 0;
}
