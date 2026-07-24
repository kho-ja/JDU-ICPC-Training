#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int q;
    cin >> q;
    set<int> st;
    while (q--) {
        int qi;
        cin >> qi;
        qi--;
        if (st.count(qi) == 0) st.insert(qi);
        else st.erase(qi);
    }
    for (auto qi: st) {
        reverse(s.begin() + qi, s.end() - qi);
    }
    cout << s;
    return 0;
}
