// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, mx = 0;
//     cin >> n;
//     vector<int> v(n), dp(n, 1);
//     for (int i = 0; i < n; i++) {
//         cin >> v[i];
//         for (int j = 0; j < i; j++)
//             if (v[i] > v[j])
//                 dp[i] = max(dp[i], dp[j] + 1);
//         mx = max(mx, dp[i]);
//     }
//     cout << mx;
//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> tmp;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        auto it = lower_bound(tmp.begin(), tmp.end(), x);
        if (it == tmp.end())
            tmp.push_back(x);
        else
            *it = x;
    }
    cout << tmp.size();
    return 0;
}
