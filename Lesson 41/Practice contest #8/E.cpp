#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> p;
  for (int i = 0, x; i < 5; i++) {
    cin >> x;
    p.insert(x);
  }
  set<int> p1;
  p1 = p;
  for (int i = 0, x; i < 4; i++) {
    cin >> x;
    p.erase(x);
  }

  for (auto &x : p)
    cout << x << " ";

  cout << "\n";

  for (int i = 0, x; i < 3; i++) {
    cin >> x;
    p1.erase(x);
  }

  for (auto &x : p1)
    cout << x << " ";

  return 0;
}
