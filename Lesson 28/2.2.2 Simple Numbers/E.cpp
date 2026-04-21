#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<int> primeFactory(int n) {
    vector<int> primes;
    for (unsigned int i = 2; i * i <= n; i++)
        while (n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    if (n > 1) primes.push_back(n);
    return primes;
}

int main() {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    cout << primeFactory(a / g).size() + primeFactory(b / g).size() << endl;
    return 0;
}