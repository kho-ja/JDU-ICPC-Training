#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n, x = 2;
    cin >> n;
    while (!is_prime(x) || !is_prime(n - x)) x++;
    cout << x << " " << n - x << endl;
    return 0;
}