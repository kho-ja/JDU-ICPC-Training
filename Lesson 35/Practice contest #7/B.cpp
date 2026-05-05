#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size() - 1; i++) {
      if (s[i] + s[i + 1] == 10 + 2 * '0') {
        s.erase(i, 2);
        i-=2;
      }
    }
    cout << s.size() << endl;
  }
  return 0;
}
