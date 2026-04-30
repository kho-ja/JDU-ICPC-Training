#include <iostream>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> friendlist;
vector<bool> group, resg;
int n, mx = -1;

void rec(int i, int k, int sum) {
    if (i != n) {
        int c[2] = { 0, 0 };
        for (int j : friendlist[i])
            c[group[j]]++;
        if (k > 0) {
            group[i] = 1;
            rec(i + 1, k - 1, sum + c[1]);
        }
        if (n - i > k) {
            group[i] = 0;
            rec(i + 1, k, sum + c[0]);
        }
    }
    else {
        if (sum > mx) {
            mx = sum;
            resg = group;
        }
    }
}

int main() {
    int k, m;
    cin >> n >> k >> m;
    friendlist.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a > b) swap(a, b);
        friendlist[b].push_back(a);
    }

    group.resize(n);
    rec(0, k, 0);
    for (int i = 0; i < n; i++)
        if (resg[i])
            cout << i + 1 << ' ';

    return 0;
}