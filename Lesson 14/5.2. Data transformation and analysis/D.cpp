#include <iostream>
using namespace std;

int main() {
    int a[1000], l1, r1, l2, r2, n;
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    for (; l1 < r1; l1++, r1--) {
        swap(a[l1], a[r1]);
    }
    for (; l2 < r2; l2++, r2--) {
        swap(a[l2], a[r2]);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}