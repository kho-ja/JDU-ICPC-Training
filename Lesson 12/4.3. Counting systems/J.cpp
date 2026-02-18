#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    string s;
    do {
        int x = n % -3;
        if (x < 0) x += 3;
        s = char(x + 48) + s;
        n = (n - x) / -3;
    } while (n);

    cout << s << "\n";
    return 0;
}