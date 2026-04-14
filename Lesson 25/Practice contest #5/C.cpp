#include <iostream>
using namespace std;
int c[4];
int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ++c[(x > 18) + (x > 35) + (x > 60)];
    }
    for (int x : c) cout << x << " ";
    return 0;
}
