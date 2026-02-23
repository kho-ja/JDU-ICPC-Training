#include <iostream>
using namespace std;

int main() {
    int a[100], n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    int ans = n + 1;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}