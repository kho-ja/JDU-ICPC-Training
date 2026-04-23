#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, cnt = 0;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        if (to_string(i) <= s) cnt++;

    cout << cnt;
    return 0;
}