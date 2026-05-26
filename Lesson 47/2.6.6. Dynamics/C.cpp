#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> f(5);
    f = {0, 1, 1, 2, 4};
    f.resize(n + 1);

    for (int i = 5; i <= n; i++)
        f[i] = 2 * f[i - 1] - f[i - 2] + f[i - 3] - f[i - 4];

    cout << f[n];
}
