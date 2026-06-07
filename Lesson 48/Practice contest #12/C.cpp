#include <iostream>
#include <map>
using namespace std;

map<int, string> a;
int main() {
    a[1] = "bir";
    a[2] = "ikki";
    a[3] = "uch";
    a[4] = "to'rt";
    a[5] = "besh";
    a[6] = "olti";
    a[7] = "yetti";
    a[8] = "sakkiz";
    a[9] = "to'qqiz";
    a[10] = "o'n";
    a[20] = "yigirma";
    a[30] = "o'ttiz";
    a[40] = "qirq";
    a[50] = "ellik";
    a[60] = "oltmish";
    a[70] = "yetmish";
    a[80] = "sakson";
    a[90] = "to'qson";
    a[100] = "yuz";
    a[1000] = "ming";

    int n;
    cin >> n;

    if (n == 0) {
        cout << "nol" << endl;
        return 0;
    }

    string res;
    for (int i = 1; n > 0; i *= 10, n /= 10) {
        int d = n % 10;
        if (d == 0) continue;

        if (i == 1)
            res = a[d] + " " + res;
        else if (i == 10)
            res = a[d * 10] + " " + res;
        else
            res = a[d] + " " + a[i] + " " + res;
    }

    if (!res.empty()) res.pop_back();
    cout << res << endl;
    return 0;
}
