#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 1LL * n * (n - 1) * (n - 2) * (n - 3) / 24;
    cout << ans << endl;
    return 0;
}
