#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        int x = 0;
        cin >> s;

        for (char c : s)
            x = (x * 2 + (c - '0')) % 7;

        cout << (x == 0 ? "Yes\n" : "No\n");
    }
    return 0;
}