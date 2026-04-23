#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    bool absent = true;
    vector<int> s(m + 1);

    for (int i = 1; i <= (m >> 1); i++)
        for (int j = i + i; j <= m; j += i)
            s[j] += i;

    for (int i = n; i <= m; i++)
        if (i < s[i] && s[i] <= m && s[s[i]] == i) {
            cout << i << " " << s[i] << " \n";
            absent = false;
        }

    if (absent) cout << "Absent";
    return 0;
}