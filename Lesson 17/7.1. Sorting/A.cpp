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
    int cnt = 0;
    do {
        changed = false;
        for (int i = 0; i < n - 1 - cnt; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                changed = true;
                swaps++;
            }
        }
        cnt++;
    } while (changed);

    cout << swaps;
    return 0;
}