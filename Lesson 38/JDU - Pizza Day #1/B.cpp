#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << 1ll * n * (m + 1) + 1ll * m * (n + 1);
    return 0;
}