#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> lst(90);
string s = "NSWEUD";
vector<vector<int>> memo(90, vector<int>(101));

int get(char c, int p) {
    if (memo[c][p] == 0) {
        memo[c][p] = 1;
        if (p > 1)
            for (char C : lst[c])
                memo[c][p] += get(C, p - 1);
    }
    return memo[c][p];
}

int main() {
    for(char c:s) getline(cin, lst[c]);
    char c;
    int p;
    cin >> c >> p;
    cout << get(c, p);
    return 0;
}
