#include <iostream>
using namespace std;

int main() {
    int n1, m1, n2, m2, one = 40;
    cin >> n1 >> m1 >> n2 >> m2;
    int before = n1 + m1 * one;
    int after = n2 + m2 * one;
    int res = before - after;
    cout << res << "\n" << (res + one - 1) / one;
}