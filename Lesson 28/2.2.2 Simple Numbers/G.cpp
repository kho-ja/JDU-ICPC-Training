#include <iostream>
#include <vector>
using namespace std;


bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    while (n > 1) {
        int x = 1;
        while (!isPrime(n + x)) x++;
        for (int l = x, r = n; l < r; l++, r--)
            cout << l << " " << r << "\n";
        n = x - 1;
    }

    return 0;
}