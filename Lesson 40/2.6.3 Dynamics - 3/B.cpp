#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
using ll = __int128;

ostream& operator<<(ostream& os, __int128& x) {
    string s = "", sign = "";
    if (x < 0) sign = "-", x = -x;
    do {
        s = char(x % 10 + '0') + s;
        x /= 10;
    } while (x > 0);
    os << sign << s;
    return os;
}

int main () {
    int n;
    cin >> n;
    vector<vector<ll>> dp(n , vector<ll>(10));
    dp[0] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1};

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][4] + dp[i-1][6];
        dp[i][1] = dp[i-1][6] + dp[i-1][8];
        dp[i][2] = dp[i-1][7] + dp[i-1][9];
        dp[i][3] = dp[i-1][8] + dp[i-1][4];
        dp[i][4] = dp[i-1][0] + dp[i-1][3] + dp[i-1][9];
        dp[i][6] = dp[i-1][7] + dp[i-1][1] + dp[i-1][0];
        dp[i][7] = dp[i-1][6] + dp[i-1][2];
        dp[i][8] = dp[i-1][3] + dp[i-1][1];
        dp[i][9] = dp[i-1][4] + dp[i-1][2];
    }

    __int128 sum = 0;
    for (int i = 0; i < 10; i++) sum += dp[n-1][i];
    cout << sum << '\n';
    return 0;
}
