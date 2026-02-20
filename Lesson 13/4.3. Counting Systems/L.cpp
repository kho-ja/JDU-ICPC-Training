#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() < b.size()) swap(a, b);
    b = string(a.size() - b.size(), '0') + b;

    for (int i = 0; i < b.size(); i++)
        if (b[i] == '1') a[i]++;

    bool changed = false;
    do {
        changed = false;

        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] > '1') {
                a[i] -= 2;
                if (i == a.size() - 1);
                else if (i == a.size() - 2) a[i + 1]++;
                else a[i + 2]++;

                if (i == 0) {
                    a = "0" + a;
                    i++;
                }
                a[i - 1]++;

                changed = true;
            }
            else if (i < a.size() - 1 && a[i] > '0' && a[i + 1] > '0') {
                a[i]--;
                a[i + 1]--;
                if (i == 0) {
                    a = "0" + a;
                    i++;
                }
                a[i - 1]++;

                changed = true;
            }
    } while (changed);

    cout << a;
    return 0;
}