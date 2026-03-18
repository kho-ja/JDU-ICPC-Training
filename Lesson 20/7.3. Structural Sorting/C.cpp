#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<vector<string>, string>> a(n);

    for (int i = 0; i < n; i++) {
        string cnt, name, surname;
        vector<string> score(0);
        cin >> cnt >> name >> surname;
        for (int i = 0; i < 6; i++) {
            string s;
            cin >> s;
            if (s != "x") score.push_back(s);
        }
        sort(score.rbegin(), score.rend());
        a[i] = { score, cnt + " " + name + " " + surname };
    }

    sort(a.rbegin(), a.rend());

    if (!a[0].first.empty()) {
        for (int i = 0; i < n && !a[i].first.empty() && i < 3; i++) {
            cout << i + 1 << ") " << a[i].second << " " << a[i].first[0] << "\n";
        }
    }
    else {
        cout << "No results.\n";
    }
    return 0;
}