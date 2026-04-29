#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int diff = b - a - 5;
    if (diff > 60) {
        cout << 15;
    }
    else if (diff > 40) {
        cout << 9;
    }
    else if (diff > 20) {
        cout << 5;
    }
    else if (diff > 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }
    return 0;
}