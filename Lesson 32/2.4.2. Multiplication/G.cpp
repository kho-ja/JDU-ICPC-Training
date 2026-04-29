#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a, b;
    char c;
    cin >> a >> c >> b;
    cout << a / b;
    a %= b;
    if (a == 0) return 0;
    string s = ".";
    vector<int> pos(b);
    while (a != 0 && pos[a] == 0) {
        pos[a] = (int)s.size();
        s.push_back((a * 10 / b) + '0');
        a = (a * 10) % b;
    }
    if (a != 0) s.insert(pos[a], "("), s.push_back(')');
    cout << s;
    return 0;
}