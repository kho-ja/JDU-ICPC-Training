#include <iostream>
#include <vector>
using namespace std;

int digits[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        digits[a[i] + 100]++;
    }

    for (int i = 1; i < 201; i++) digits[i] += digits[i - 1];
    int* b = new int[n];
    for (int i = n - 1; i >= 0; i--) b[--digits[a[i] + 100]] = a[i];
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    return 0;
}