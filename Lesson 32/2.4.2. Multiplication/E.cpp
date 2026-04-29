#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    a %= b;
    for (int i = 1; i < k; i++) a = a * 10 % b;
    cout << a * 10 / b;
    return 0;
}