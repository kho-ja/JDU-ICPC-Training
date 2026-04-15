#include <iostream>
using namespace std;

int n, res = 0;
bool col[10];
bool table[10][10];
bool d1[19];
bool d2[19];

void brute_force(int i, int k) {
    if (k == 0) {
        res++;
    }
    else {
        if (n - i != k)
            brute_force(i + 1, k);
        for (int j = 0; j < n; j++) {
            if (col[j]) continue;
            if (d1[i + j]) continue;
            if (d2[i - j + n - 1]) continue;
            if (i >= 1 && j >= 2 && table[i - 1][j - 2]) continue;
            if (i >= 2 && j >= 1 && table[i - 2][j - 1]) continue;
            if (i >= 2 && j + 1 < n && table[i - 2][j + 1]) continue;
            if (i >= 1 && j + 2 < n && table[i - 1][j + 2]) continue;
            col[j] = d1[i + j] = d2[i - j + n - 1] = table[i][j] = true;
            brute_force(i + 1, k - 1);
            col[j] = d1[i + j] = d2[i - j + n - 1] = table[i][j] = false;
        }
    }
}

int main() {
    int k;
    cin >> n >> k;
    brute_force(0, k);
    cout << res << "\n";
    return 0;
}