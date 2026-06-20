#include <ios>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, res = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        res += x;
    }
    cout << res - n;
    return 0;
}
