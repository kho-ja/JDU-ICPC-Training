#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    int freq[26] = { 0 };
    for (char c : s) {
        freq[c - 'a']++;
    }
    int cnt = 0, res = 0;
    for (int i = 0; i < 26; i++) cnt += freq[i] > 0;
    cnt = cnt - 2;
    sort(freq, freq + 26);
    for (int i = 0; i <= 25 && cnt > 0; i++) {
        if (freq[i] > 0) {
            res += freq[i];
            cnt--;
        }
    }
    cout << res << "\n";
    return 0;
}