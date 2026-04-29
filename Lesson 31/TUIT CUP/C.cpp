#include <iostream>
#include <vector>
using namespace std;

#define point pair<int, int>

point read() {
    char c;
    int r;
    cin >> c >> r;
    return { c - 'A', r - 1 };
}

point kg, kj, r1, r2;

bool in_danger(int c, int r) {
    if (c < 0 || c >= 8 || r < 0 || r >= 8) return true;
    if (max(abs(kj.first - c), abs(kj.second - r)) == 1) return true;
    for (int i = 0; i < 2; i++) {
        if (r1.first == c) {
            if (kj.first != c) return true;
            if (kj.second < min(r1.second, r2.second) || kj.second > max(r1.second, r2.second)) return true;
        }
        if (r1.second == r) {
            if (kj.second != r) return true;
            if (kj.first < min(r1.first, r2.first) || kj.first > max(r1.first, r2.first)) return true;
        }
        swap(r1, r2);
    }
    return false;
}


int main() {
    kg = read();
    r1 = read();
    r2 = read();
    kj = read();

    int res = 0;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (i != 0 || j != 0)
                res += in_danger(kg.first + i, kg.second + j);

    if (in_danger(kg.first, kg.second)) {
        if (res == 8) cout << "Mat ";
        else cout << "Shah " << 8 - res;
    }
    else {
        if (res == 8) cout << "Pat";
        else cout << "Erkin " << 8 - res;
    }

    return 0;
}