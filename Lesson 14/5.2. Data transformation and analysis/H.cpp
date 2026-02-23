#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a[100000], k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    k %= n;
    if (k < 0) k += n;
    int start = (n - k) % n;
    for (int i = start; i < n; i++) {
        cout << a[i] << " ";
    }
    for (int i = 0; i < start; i++) {
        cout << a[i] << " ";
    }
    return 0;
}