#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long res = 0;
    n += (3 - n % 3) % 3;
    for (int i = n; i <= m; i += 3) {
        if (i % 7 == 0) continue;
        res += i;
    }
    cout << res;
    return 0;
}