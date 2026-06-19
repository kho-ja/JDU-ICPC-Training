#include <iostream>
using namespace std;

int main () {
    long long n, k;
    cin >> n >> k;
    cout << n * (k + 1) * k / 2 - k * k + 1;
    return 0;
}
