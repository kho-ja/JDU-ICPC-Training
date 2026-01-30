#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while (b) swap(a %= b, b);
    cout << a << '\n';
}