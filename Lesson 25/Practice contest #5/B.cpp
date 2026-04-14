#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int res, n;
vector <int> arr;
vector <int> asc(25, 0);
vector <int> desc(25, 2e9);

void brute_force(int i, int ascc, int descc) {
    if (ascc + descc >= res) return;
    if (i == n) {
        res = ascc + descc;
        return;
    }
    else {
        int id = (int)(lower_bound(asc.begin(), asc.end(), arr[i], greater<int>()) - asc.begin());
        int prev = asc[id];
        asc[id] = arr[i];
        brute_force(i + 1, max(ascc, id + 1), descc);
        asc[id] = prev;


        id = (int)(lower_bound(desc.begin(), desc.end(), arr[i]) - desc.begin());
        prev = desc[id];
        desc[id] = arr[i];
        brute_force(i + 1, ascc, max(descc, id + 1));
        desc[id] = prev;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    arr.resize(n);
    for (int& x : arr) cin >> x;
    res = n / 2 + 1;
    brute_force(0, 0, 0);

    if (res == n / 2 + 1) res = 0;
    cout << res << "\n";
    return 0;
}
