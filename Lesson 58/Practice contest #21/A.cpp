#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    string s1, s2;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++) {
        if (s1[i] == '_' && s2[i] == '_') cnt ++;
    }
    cout << cnt;
    return 0;
}
