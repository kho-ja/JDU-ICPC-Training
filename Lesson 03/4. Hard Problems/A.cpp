#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, t, m;
    cin >> n;
    t = n * 2 % 5;
    m = (n - t * 3) / 5;
    cout << m << " " << t;
}