#include <iostream>
using namespace std;

int main() {
    string s1, s2, res;
    cin >> s1 >> s2;
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        char c = s1[i];
        if (c == 'x') res+=s2[cnt++];
        else res+=c;
    }
    cout << res;
    return 0;
}
