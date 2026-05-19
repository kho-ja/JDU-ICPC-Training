#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> a;

int countMax(string a) {
    a += a;
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        char x = a[i];
        int j = 1;
        while (a[i + j] == x) j++;
        res = max(res, j);
    }
    return res;
}

void step(vector<int> &a) {
    int i = (int)a.size() - 1;
    while (i >= 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i >= 0) a[i] = 1;
}

int findMaxCountMutation(vector<string> a) {
    int maxVal = 0, len = (int)a.size() * (int)a.size() - 1;
    vector<int> permutationHelper((int)a.size(), 0);
    string s = "";
    for (int i = 0; i < len; i++) {
        if (permutationHelper[i] == 0)
            s += a[i];
        else
            s += string(a[i].rbegin(), a[i].rend());
        step(permutationHelper);
        maxVal = max(maxVal, countMax(s));
    }

    return maxVal;
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto &s : a) cin >> s;

    int maxVal = findMaxCountMutation(a);

    cout << maxVal;

    return 0;
}
