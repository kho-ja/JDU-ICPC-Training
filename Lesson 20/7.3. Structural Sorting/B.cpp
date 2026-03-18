#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, string>> a(n);

    for (int i = 0; i < n; i++) {
        int course;
        char level;
        string name, surname, ip;
        cin >> surname >> name >> course >> level >> ip;
        string info = string(1, level) + " " + surname + " " + name + " " + ip;
        a[i] = { course, info };
    }

    sort(a.begin(), a.end());

    for (const auto& p : a)
        cout << p.first << p.second << "\n";
    return 0;
}