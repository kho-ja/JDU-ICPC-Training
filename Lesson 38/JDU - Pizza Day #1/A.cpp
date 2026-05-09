#include <ios>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int x, l, r;
    cin >> x >> l >> r;
    int max = 2 * r;
    int min = 2 * -r;
    if (x < min || x > max) {
      cout << "impossible";
      continue;
    }
    if (x < 0) {
      int L = -l;
      while (abs(x - L) > l) {
        L--;
      }
      cout << L << " " << x - L << "\n";
      continue;
    }
    int L = l;
    while (x - L < l || x - L > r) {
      L++;
    }
    cout << L << " " << x - L << "\n";
  }
  return 0;
}
