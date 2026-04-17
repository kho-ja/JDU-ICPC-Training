#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string s;
int i = 0;

void error() {
    cout << "Error";
    exit(0);
}

void skipSpaces() {
    while (i < s.size() && s[i] == ' ') i++;
    if (i == s.size()) error();
}

double calculate();

double readNumber() {
    int l = i;
    while (isdigit(s[i])) i++;
    if (s[i] == '.') {
        i++;
        while (isdigit(s[i])) i++;
    }
    if (s[i] == 'e') {
        i++;
        if (s[i] == '+' || s[i] == '-') i++;
        if (!isdigit(s[i])) error();
        while (isdigit(s[i])) i++;
    }
    return stod(s.substr(l, i - l));
}

double nextNumber() {
    skipSpaces();
    if (isdigit(s[i])) return readNumber();
    if (s[i] == '(') return calculate();
    if (s.substr(i, 3) == "sin") {
        i += 3;
        return sin(calculate());
    }
    if (s.substr(i, 3) != "cos") error();
    i += 3;
    return cos(calculate());
}

char nextOperator() {
    skipSpaces();
    if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != ')') error();
    return s[i++];
}

double calculate() {
    skipSpaces();
    if (s[i] != '(') error();
    i++;
    double res = 0, temp = nextNumber();
    char op;
    while ((op = nextOperator()) != ')') {
        switch (op) {
        case '+':
            res += temp;
            temp = nextNumber();
            break;
        case '-':
            res += temp;
            temp = -nextNumber();
            break;
        case '*':
            temp *= nextNumber();
            break;
        case '/':
            temp /= nextNumber();
            break;
        default:
            error();
        }
    }
    return res + temp;
};

int main() {
    getline(cin, s);
    for (char& c : s) c = tolower(c);
    s = '(' + s + ')';
    cout.precision(10);
    cout << fixed << calculate();
    return 0;
}