#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n);
    for(int i = 1, k = 0; i < n; i++) {
        while (k > 0 && s[k] != s[i]) k = p[k - 1];
        if (s[k] == s[i]) k++;
        p[i] = k;
    }
    return p;
}

int main() {
    string s;
    cin >> s;
    for (int x: prefix_function(s))
        cout << x << " ";
    return 0;
}
