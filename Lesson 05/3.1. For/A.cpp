#include <iostream>
using namespace std;

int main() {
    int n, s = 0, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        s += x;
    }
    cout << min(s, n-s);
}