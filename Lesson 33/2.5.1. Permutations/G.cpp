#include <iostream>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    unsigned int n, k, t;
    cin >> n;
    k = __builtin_popcount(n);
    n += n & -n;
    n |= (1 << (k - __builtin_popcount(n))) - 1;
    cout << n;
    return 0;
}