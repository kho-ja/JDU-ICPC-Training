#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> st;
    int n;
    cin >> n;
    long long res = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        st.push(x);
    }
    while (st.size() > 1) {
        int x = st.top();
        st.pop();
        x += st.top();
        st.pop();
        st.push(x);
        res += x;
    }

    cout.precision(2);
    cout << fixed;
    cout << res / 20.0;

    return 0;
}
