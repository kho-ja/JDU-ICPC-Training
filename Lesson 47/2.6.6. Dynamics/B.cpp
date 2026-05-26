#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int get (vector<int> &a) {
    stack<int> h, id;
    int res = 0;
    for (int i = 0, last; i < a.size(); i++) {
        last = 0;
        while (!h.empty() && h.top() > a[i]) {
            last = id.top();
            h.pop();
            id.pop();
        }
        h.push(a[i]);
        id.push(last);
    }
    while (!h.empty()) {
        res = max(res, ((int)a.size() - id.top()) * h.top());
        h.pop();
        id.pop();
    }
    return res;
}

int main() {
    int n, m,res = 0;
    cin >> n >> m;
    vector<int> h(m);
    string row;
    for (int i = 0; i < n; i++) {
        cin >> row;
        for (int j = 0; j < m; j++) {
            h[j] = row[j] == '0' ? 0 : h[j] + 1;
        }
        res = max(res, get(h));
    }
    cout << res;
    return 0;
}
