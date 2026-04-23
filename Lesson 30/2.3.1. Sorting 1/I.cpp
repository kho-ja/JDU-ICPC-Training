#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int j = 0; j < 2; j++) {
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        if (j == 0) sort(a.rbegin(), a.rend());
        else sort(a.begin(), a.end());
        
        for (auto& [v, i] : a) cout << i + 1 << " ";
        cout << "\n";
    }

    return 0;
}