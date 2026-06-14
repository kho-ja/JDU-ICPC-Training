#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a;
    cin >> a;
    vector<int> v(26);
    for (auto &x: a) v[x-'a']++;

    int res = 0;
    bool odd = false;
    for (auto &x: v) {
        if (x % 2 != 0) {
            res += x - 1;
            odd = true;
        }
        else res += x;
    }
    cout << res + odd;
    return 0;
}
