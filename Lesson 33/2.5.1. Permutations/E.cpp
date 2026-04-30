#include <iostream>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    do {
        bool f = true;
        for (int i = 1; i < n && f; i++)
            f = f && (abs(v[i] - v[i - 1]) <= k);
        cnt += f;
    } while (next_permutation(v.begin(), v.end()));
    cout << cnt;
    return 0;
}