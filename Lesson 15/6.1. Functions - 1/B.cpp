#include <iostream>
using namespace std;

int IsLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    char a, b, c;
    cin >> a >> b >> c;
    cout << IsLetter(a) + IsLetter(b) + IsLetter(c) << "\n";
    return 0;
}