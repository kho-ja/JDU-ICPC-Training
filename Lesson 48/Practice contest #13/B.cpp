#include <iostream>
using namespace std;

int main() {
    long long n, res = 0;
    cin >> n;
    res = (1 + n) * n / 2;
    if (n < 0) {
        res = -res;
        res += n + 1;
    }
    cout << res;
    return 0;
}
