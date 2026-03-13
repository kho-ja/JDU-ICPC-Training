#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int digits[2000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        digits[x + 1000000]++;
    }

    int mxid = 0;
    for (int i = 0; i < 2000001; i++)
        if (digits[i] > digits[mxid])
            mxid = i;

    for (auto x : a) if (x != mxid - 1000000) cout << x << " ";
    for (int i = 0; i < digits[mxid]; i++) cout << mxid - 1000000 << " ";

    cout << "\n";
    return 0;
}