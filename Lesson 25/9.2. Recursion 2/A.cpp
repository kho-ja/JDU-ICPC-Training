#include <iostream>
using namespace std;

int combinations_cnt(int n, int k) {
    if (n == 0) return 1;
    if (k == 0) return 0;
    if (n < k) k = n;
    int res = 0;
    for (int i = 1; i <= k; i++)
        res += combinations_cnt(n - i, i - 1);
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << combinations_cnt(n, n) << endl;
    return 0;
}