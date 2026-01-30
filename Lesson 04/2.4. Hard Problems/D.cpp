#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << n * (m + 1) + m * (n + 1) + n + m - 2 * (n * m % 2 || min(n, m) == 1);
}