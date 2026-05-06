#include <ios>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, m, n, name;
    cin >> l >> m >> n;
    map<string, int> mp;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> name;
        cin.ignore();
        getline(cin, s);
        mp[s] = name;
    }

    int ok = 0;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (mp.count(s)) {
            cout << mp[s] << "\n";
            ++ok;
        }
        else cout << "-" << "\n";
    }
    cout << "OK=" << ok << " BAD=" << n - ok << "\n";
    return 0;
}
