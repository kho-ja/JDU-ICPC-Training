#include <iostream>
using namespace std;

bool used[1000];

int main () {
    string s;
    int cnt = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != '0')
            for (int j = i + 1; j < s.size(); ++j)
                for (int k = j + 1; k < s.size(); ++ k) {
                    int v = (s[i] - 48) * 100 + (s[j] - 48) * 10 + (s[k] - 48);
                    if (!used[v]) {
                        used[v] = true;
                        cnt ++;
                    }
                }
    cout << cnt;

    return 0;
}
