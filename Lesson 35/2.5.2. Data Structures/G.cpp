#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, mx = 0;
    cin >> n;
    map<string, int> mp;
    vector<string> order;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> t >> s >> t;

        if (isupper(t[0]))
            cin >> t;
        if (t != "w") continue;

        if (mp.count(s) == 0) order.push_back(s);
        mx = max(mx, ++mp[s]);
    }

    if (mx == 0) cout << "NO DATA!";
    else if (mx == 1) cout << "UNIQUE!";
    else {
        bool comma = false;
        for (auto s: order) {
            if (mp[s] != mx) continue;
            if (comma) cout << ",";
            else comma = true;
            cout << s;
        }
    }
    return 0;
}
