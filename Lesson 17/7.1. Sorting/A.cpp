#include <iostream>
using namespace std;

int main() {
    int n, swaps = 0;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool changed = true;
    do {
        changed = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                changed = true;
                swaps++;
            }
        }
    } while (changed);

    cout << swaps;
    return 0;
}