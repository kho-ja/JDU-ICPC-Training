#include <iostream>
#include <set>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  set<string> s;
  for (int i = 0; i < b.size(); i++)
      s.insert(b.substr(i) + b.substr(0, i));
  int res = 0;
  for (int i = 0; i <= a.size() - b.size(); i++)
      res += s.count(a.substr(i, b.size()));
  cout << res << endl;
  return 0;
}
