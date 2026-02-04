#include <iostream>
using namespace std;

int main() {    
    int L = 1, R = 1e9, x;
    char c;
    do {
        x = (L + R) / 2;
        cout << x << endl;
        cin >> c;
        if (c == '=') L = R = x;
        else if (c == '>') L = x + 1;
        else R = x;
    } while (c != '=');
}