#include <iostream>
#include <stack>
using namespace std;

bool isOK(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false;
            if (st.top() == '(' && c != ')') return false;
            if (st.top() == '[' && c != ']') return false;
            if (st.top() == '{' && c != '}') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main () {
    string s;
    while (cin >> s) {
        cout << !isOK(s);
    }
    return 0;
}
