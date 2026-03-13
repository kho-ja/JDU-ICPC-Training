#include <iostream>
using namespace std;

struct mass {
    int v;
    string k;
    double u;
    void read() {
        cin >> v >> k;
        u = v;
        switch (k.back()) {
        case 'p': u *= 16380; break;
        case 't': u *= 1e6; break;
        }
        switch (k.front()) {
        case 'm': u *= 1e-3; break;
        case 'k': u *= 1e3; break;
        case 'M': u *= 1e6; break;
        case 'G': u *= 1e9; break;
        }
    }
    void writeln() {
        cout << v << " " << k << "\n";
    }
    double operator>(const mass& other) const {
        return u > other.u;
    }
};

int main() {
    int n;
    cin >> n;
    mass* a = new mass[n];

    for (int i = 0, j; i < n; i++) {
        a[i].read();
        j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            swap(a[j - 1], a[j]);
            j--;
        }
    }

    for (int i = 0; i < n; i++) a[i].writeln();
    delete[] a;

    return 0;
}