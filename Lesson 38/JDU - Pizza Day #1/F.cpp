#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto &x : A)
    cin >> x;
  vector<int> dp(n);
  dp[0] = 2e9;
  dp[1] = max(A[1], A[0]) - min(A[0], A[1]);
  dp[2] = max({A[2], A[1], A[0]}) - min({A[2], A[1], A[0]});
  for (int i = 3; i < n; i++) {
    dp[i] = min(
        max(abs(A[i] - A[i - 1]), dp[i - 2]),
        max(max({A[i], A[i - 1], A[i - 2]}) - min({A[i], A[i - 1], A[i - 2]}),
            dp[i - 3]));
  }
  cout << dp[n - 1];
  return 0;
}
