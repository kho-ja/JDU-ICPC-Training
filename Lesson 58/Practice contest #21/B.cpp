#include <iostream>
using namespace std;

int main() {
    int n, J = 0, L = 100000000;
    string s;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        int j, l;
        cin >> j >> l;
        J += j;
        L = min(L, l);
    }
    cout << s.substr(J, L);
    return 0;
}
