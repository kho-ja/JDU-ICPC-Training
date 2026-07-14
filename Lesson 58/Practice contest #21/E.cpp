#include <iostream>
using namespace std;

int main() {
    string s;
    int cnt = 0;
    cin >> s;
    if (s[0] == '1' || s[0] == '9') cnt ++;
    else cnt += 2;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '0' || s[i] == '9') cnt ++;
        else cnt += 2;
    }
    cout << cnt;
    return 0;
}
