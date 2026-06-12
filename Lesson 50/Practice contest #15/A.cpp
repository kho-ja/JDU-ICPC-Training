#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> numscnt;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        numscnt[x]++;
    }
    int res = 0;
    for (auto &[m, n]: numscnt) {
        res += ((n - 1) * n) / 2;
    }
    cout << res;
    return 0;
}
