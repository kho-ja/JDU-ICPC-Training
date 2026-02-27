#include <iostream>
#include <string>
using namespace std;

long long add(long long a, long long b) {
    string s;
    while (a || b) {
        s = to_string((a % 10 + b % 10)) + s;
        a /= 10;
        b /= 10;
    }
    return stoll(s);
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long A = add(add(b, c), a);
    long long B = add(add(a, c), b);
    long long C = add(add(a, b), c);

    if (A > B) swap(A, B);
    if (A > C) swap(A, C);
    if (B > C) swap(B, C);

    cout << (A != C ? "YES" : "NO") << "\n" << A << "\n";
    if (A != B) cout << B << "\n";
    if (B != C) cout << C << "\n";

    return 0;
}