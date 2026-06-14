#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int N, W, H;
  cin >> N >> W >> H;
  int d = sqrt(W * W + H * H);
  while (N--) {
    int x;
    cin >> x;
    cout << (x <= d ? "YES" : "NO") << endl;
  }
  return 0;
}