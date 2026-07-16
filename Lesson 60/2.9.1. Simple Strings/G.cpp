#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string solve(string a, string b) {
    a[0] = tolower(a[0]);
    b[0] = tolower(b[0]);
    int i = a.find(b);
    if (i == -1) {
        for (int l = min(a.size(), b.size() - 1); l >= 0; l--) {
            if (a.substr(a.size() - l) == b.substr(0, l)) {
                string res = a + b.substr(l);
                res[0] = toupper(res[0]);
                res[res.size()-b.size()] = toupper(res[res.size()-b.size()]);
                return res;
            }
        }
    } else {
        a[0] = toupper(a[0]);
        if (i == 0) {
            i = a.find(b);
            if (i == -1) i = 0;
        }
        a[i] = toupper(a[i]);
        return a;
    }
    return "";
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string x = solve(s1, s2);
    string y = solve(s2, s1);
    cout << (x.size() < y.size() ? x : x.size() > y.size() ? y : min(x, y));
    return 0;
}
