#include <iostream>
#include <vector>
using namespace std;

int main () {
    int x[3], w, cnt = 0;
    cin >> x[0] >> x[1] >> x[2] >> w;
    vector<int> dp(w+1);
    dp[0] = 1;
    for (auto y:x)
        for (int k = y; k <= w; ++k)
            dp[k] += dp[k-y];
    cout << dp[w];
    return 0;
}
