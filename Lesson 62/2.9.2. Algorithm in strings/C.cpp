#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, j = 0, r = 0; i < n; i++) {
        z[i] = r > i ? min(r - i + 1, z[i - j]) : 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r) {
            j = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    for (auto i:z_function(s)) {
        cout << i << " ";
    }
    return 0;
}
