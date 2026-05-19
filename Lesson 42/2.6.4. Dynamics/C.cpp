#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int mod = 1000000009;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> lst(100);
    vector<vector<int>> dp(n + 1, vector<int>(100));

    for (int i = 100; i < 1000; i++) {
        if (is_prime(i)) {
            lst[i % 100].push_back(i / 10);
            dp[3][i % 100]++;
        }
    }

    for (int i = 4; i <= n; i++)
        for (int j = 0; j < 100; j++)
            for (int k : lst[j])
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;

    int sum = 0;
    for (int x : dp[n]) sum = (sum + x) % mod;

    cout << sum;
    return 0;
}
