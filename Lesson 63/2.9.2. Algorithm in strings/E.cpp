#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

vector<int> z_function(vector<int> a) {
    int n = a.size();
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        while (i + z[i] < n && a[z[i]] == a[i + z[i]]) {
            z[i]++;
        }
    }

    return z;
}

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, j = 0, r = 0; i < n; i++) {
        z[i] = r > i ? min(r - i, z[i - j]) : 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r) {
            j = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t, s;
    cin >> s >> t;
    vector<int> z = z_function(t + "#" + s);
    for (int i = t.size() + 1; i < z.size(); i++)
        if (z[i] == t.size())
            cout << i - t.size() - 1 << " ";
    return 0;
}
