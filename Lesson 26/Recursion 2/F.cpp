#include <iostream>
using namespace std;

long long count(int n, int x, int y) {
    if (x == 1 && y == 1) return 0;
    int A = 1 << (n - 1);
    if (x <= A && y <= A) return count(n - 1, y, x);
    if (x <= A) return count(n - 1, x, y - A) + 1LL * A * A;
    if (y > A) return count(n - 1, x - A, y - A) + 2LL * A * A;
    return count(n - 1, A + 1 - y, 2 * A + 1 - x) + 3LL * A * A;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << count(n, x, y) << "\n";
    return 0;
}