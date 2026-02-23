#include <iostream>
using namespace std;

int main() {
    int a[1000], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l - 1; j < r; j++) {
            cout << a[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}