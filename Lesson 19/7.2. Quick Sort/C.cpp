#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int mnid = 1;
    for (int i = 1; i < n; i++)
        if (a[i].first - a[i - 1].first < a[mnid].first - a[mnid - 1].first)
            mnid = i;

    cout << a[mnid].first - a[mnid - 1].first << "\n";
    cout << a[mnid - 1].second + 1 << " " << a[mnid].second + 1 << "\n";
    return 0;
}