#include <iostream>
using namespace std;

int main() {
  int c, l;
  cin >> c >> l;
  for (int i = 0; i < l; i++) {
    string s;
    cin >> s;
    bool isWhite = false;
    for (int j = 0; j < s.size(); j++) {
      char x = s[j];
      int n;
      if (isdigit(x)) {
        isWhite = !isWhite;
        n = x - '0';
        while (n--) {
          cout << (isWhite ? '.' : 'X');
        }
      } else if (x == '_') {
        isWhite = !isWhite;
      } else if (x == ' ') {
        cout << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}
