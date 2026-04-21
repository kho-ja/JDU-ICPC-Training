#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
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
    int n;
    cin >> n;
    bool isFirst = true;
    for (int i : primeFactory(n)) {
        if (!isFirst) cout << "*";
        else isFirst = false;
        cout << i;
    }
    return 0;
}