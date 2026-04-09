#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int n, res = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n - 1; i++)
            if (s[i] == 'S' && s[i + 1] == 'M' && s[i + 2] != 'M')
                res++;

        cout << res << "\n";
    }
    return 0;
}