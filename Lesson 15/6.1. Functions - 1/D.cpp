#include <iostream>
using namespace std;

int IsPrime(int N) {
    if (N < 2) return 0;
    for (int i = 2; i * i <= N; i++)
        if (N % i == 0) return 0;
    return N;
}

int main() {
    int a, b, c, s;
    cin >> a >> b >> c;
    s = IsPrime(a) + IsPrime(b) + IsPrime(c);
    cout << s << " " << (IsPrime(s) ? "Yes" : "No") << "\n";
    return 0;
}