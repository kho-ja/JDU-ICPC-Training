#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string res;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        res += char(toupper(s[0]));
    }
    cout << res << "\n";
    return 0;
}