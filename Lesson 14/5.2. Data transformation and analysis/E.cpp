#include <iostream>
using namespace std;

int main() {
    int n, a[100000], oneID = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            oneID = i;
        }
    }
    for (int i = oneID; i < n; i++) {
        cout << a[i] << " ";
    }
    for (int i = 0; i < oneID; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}