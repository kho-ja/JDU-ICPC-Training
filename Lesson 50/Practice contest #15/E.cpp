#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long res = 0, len = 1, cnt = 9;
    while (n > 0) {
        long long take = min(n, cnt);
        res += take * len;
        n -= take;
        cnt *= 10;
        len++;
    }
    cout << res;
    return 0;
}
