#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> m >> n;
    vector<bool> primes(n + 1, true);
    bool showed = false;

    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++)
        for (int j = i * i; j <= n; j += i)
            primes[j] = false;

    for (int i = m; i <= n; i++)
        if (primes[i]) {
            cout << i << "\n";
            showed = true;
        }

    if (!showed)
        cout << "Absent\n";

    return 0;
}