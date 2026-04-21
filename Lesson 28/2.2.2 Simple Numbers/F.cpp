#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 0;
    cin >> n;
    vector<bool> primes(n + 1, true);
    bool showed = false;

    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (primes[i])
            for (int j = i * i; j <= n; j += i)
                primes[j] = false;

    for (int i = 2; i <= n; i++)
        if (primes[i]) cnt++;

    cout << cnt << "\n";

    return 0;
}