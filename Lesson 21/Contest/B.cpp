#include <iostream>
using namespace std;

int main() {
    int n, res = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        res += (3 - ((s[i] - '0' + res) % 3)) % 3;
    cout << res;
    return 0;
}