#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, res = 0;
        cin >> x;
        if (x==1) {
            cout << -1 << endl;
            continue;
        }
        res += x / 7;
        x %= 7;
        res += x / 5;
        x %= 5;
        res += x / 3;
        x %= 3;
        res += x / 2;
        x %= 2;
        
        if (x == 1) ++res;
        cout << res << endl;
    }
    return 0;
}