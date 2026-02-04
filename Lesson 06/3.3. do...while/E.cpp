#include <iostream>
using namespace std;

int main() {
    int n, mx = 0;
    do {
        cin >> n;
        if (n > mx) mx = n;
    } while (n != 0);
    cout << mx;
}