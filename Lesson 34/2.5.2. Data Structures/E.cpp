#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  vector<string> v;
  set<string> st;

  string str;
  while (cin >> str, str != "ENDOFINPUT")
    v.push_back(str);

  set<string> tmp(v.begin(), v.end());
  for (auto x : v)
    for (auto y : v)
      if (tmp.count(x + y))
        st.insert(x + y);

  int cnt = 0;
  for (auto x : v)
    cnt += st.count(x);
  cout << cnt << endl;

  return 0;
}
