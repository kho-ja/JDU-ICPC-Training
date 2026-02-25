#include <iostream>
using namespace std;

int IsDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    char a, b, c;
    cin >> a >> b >> c;
    cout << IsDigit(a) + IsDigit(b) + IsDigit(c) << "\n";
    return 0;
}