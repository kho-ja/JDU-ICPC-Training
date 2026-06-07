#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    vector<int> num(9);
    for (int i = 0; i < 9; i++) {
        cin >> num[i];
    }
    string s = "111111100";
    sort(s.begin(), s.end());
    do {
        int res = 0;
        for (int i = 0; i < 9; i++) {
            res += (s[i] != '0' ? num[i] : 0);
        }
        if (res == 100) break;
    } while (next_permutation(s.begin(), s.end()));
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') continue;
        cout << num[i] << "\n";
    }
    return 0;
}
