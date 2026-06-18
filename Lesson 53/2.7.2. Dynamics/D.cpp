#include <iostream>
#include <vector>
using namespace std;

int main() {
    string n, m;
    cin >> n;

    m = string(n.size(), '4');
    if (m > n) m = string(n.size() - 1, '7');
    else
        for (int i = 0; i < m.size(); i++) {
            m[i] = '7';
            if (m > n) m[i] = '4';
        }

    long long res = 0;
    for (char c:m) res = res * 2 + 1 + (c == '7');
    cout << res;
    return 0;
}
