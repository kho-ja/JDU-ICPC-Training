#include <iostream>
using namespace std;

int main() {
    int cnt = 0;
    string s;
    cin >> s;
    for (int i = int(s.size()) - 1; i >= 0; i--) {
        cnt++;
        if (isupper(s[i])) {
            if (cnt < 2 || cnt > 4) {
                cout << "No";
                return 0;
            }
            cnt = 0;
        }
    }
    if (cnt == 0) cout << "Yes";
    else cout << "No";
    return 0;
}