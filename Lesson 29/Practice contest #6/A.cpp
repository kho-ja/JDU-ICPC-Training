#include <iostream>
#include <string>
using namespace std;

int main() {
    // string s;
    // getline(cin, s);
    // int id = s.find('<');
    // while (id != string::npos) {
    //     if (id > 0) {
    //         s.erase(id - 1, 2);
    //     }
    //     else {
    //         s.erase(id, 1);
    //     }
    //     id = s.find('<');
    // }
    // cout << s;
    string s, res;
    cin >> s;
    for (char c : s)
        if (c == '<') {
            if (!res.empty())
                res.pop_back();
        }
        else
            res += c;
    cout << res;
    return 0;
}