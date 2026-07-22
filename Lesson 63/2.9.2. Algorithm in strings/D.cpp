#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> z_function(vector<int> a) {
    int n = a.size();
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        while (i + z[i] < n && a[z[i]] == a[i + z[i]]) {
            z[i]++;
        }
    }

    return z;
}

template<class T>
vector<int> prefix_function(T a) {
    int n = a.size();
    vector<int> z(n);
    for (int i = 1, k = 0; i < n; i++) {
        while (k > 0 && a[k] != a[i]) k = z[k - 1];
        if (a[k] == a[i]) k++;
        z[i] = k;
    }
    return z;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    int res = n - prefix_function(a).back();
    if ((n - 1) % res != 0) res = n - 1;
    cout << res;
    return 0;
}
