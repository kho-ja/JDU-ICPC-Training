#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, H = 0;
    cin >> n;
    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        H = max(H, ++mp[s]);
    }
    for (int h = H; h > 0; h--) {
        for (auto &[f, c]: mp)
            cout << ".X"[c >= h];
        cout << "\n";
    }
    return 0;
}
