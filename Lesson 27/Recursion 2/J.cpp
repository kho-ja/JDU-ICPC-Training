#include <iostream>
#include <string>
using namespace std;

using int = long long;

int res;
string s;

int calculate(int& i);

int getNumber(int& i) {
    int res = 0;
    if (s[i] == '(') {
        i++;
        int res = calculate(i);
        i++;
        return res;
    }
    else
        while (isdigit(s[i]) && i < s.size())
            res = res * 10 + s[i++] - '0';
    return res;
}

int calculate(int& i) {
    int res = getNumber(i);
    while (i < s.size() && s[i] != ')') {
        switch (s[i++]) {
        case '+':
            res += getNumber(i);
            break;
        case '-':
            res -= getNumber(i);
            break;
        case '*':
            res *= getNumber(i);
            break;
        }
    }
    return res;
}

int calculate() {
    int i = 0;
    return calculate(i);
}

void allCombinations(int i) {
    if (i == s.size()) {
        if (calculate() == res) throw 1;
    }
    else if (s[i] == ' ') {
        s[i] = '+';
        allCombinations(i + 1);
        s[i] = '-';
        allCombinations(i + 1);
        s[i] = '*';
        allCombinations(i + 1);
        s[i] = ' ';
    }
    else allCombinations(i + 1);
}

string deleteSpaces(string S) {
    string s;
    for (char c : S) {
        if (c == ' ') {
            if (s.empty() || s.back() == '(' || s.back() == ' ') continue;
            else s.push_back(c);
        }
        else if (c == ')') {
            if (s.back() == ' ') s.back() = c;
            else s.push_back(c);
        }
        else s.push_back(c);
    }
    if (s.back() == ' ') s.pop_back();
    return s;
}

int main() {
    char t;
    cin >> res >> t;
    getline(cin, s);
    s = deleteSpaces(s);
    try {
        allCombinations(0);
        cout << -1;
    }
    catch (int x) {
        cout << res << "=" << s;
    }
    return 0;
}