#include <iostream>
using namespace std;

int main() {
    char c;
    int max = 0;
    while (cin >> c) {
        if (c - '0' > max) max = c - '0';
    }
    cout << max;
    return 0;
}
