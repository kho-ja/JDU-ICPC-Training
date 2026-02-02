#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            sum += x;
        }
    }
    cout << sum / 2 << '\n';
}