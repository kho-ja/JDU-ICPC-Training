#include <iostream>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector c(n, vector(n, 0));
    vector e(n, 0);
    for (int i = 0; i < n; i++) {
        e[i] = i;
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    int ans = 1e9, sum;
    do {
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += c[i][e[i]];
        }
        ans = min(ans, sum);
    } while (next_permutation(e.begin(), e.end()));
    cout << ans << endl;
    return 0;
}