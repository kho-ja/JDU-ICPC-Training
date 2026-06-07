#include <iostream>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
            res += i;
        }
    }

    cout << res;
    return 0;
}
