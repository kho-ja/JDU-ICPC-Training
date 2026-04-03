#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int h[6], H1, H2, col1i[3] = { 0 }, col2i[3] = { 0 };
    cin >> h[0] >> h[1] >> h[2] >> h[3] >> h[4] >> h[5] >> H1 >> H2;
    sort(h, h + 6, greater<int>());
    for (int i = 0; i < 4 && col1i[2] == 0; i++) {
        col1i[0] = i;
        for (int j = i + 1; j < 5 && col1i[2] == 0; j++) {
            col1i[1] = j;
            for (int k = j + 1; k < 6; k++) {
                if (h[col1i[0]] + h[col1i[1]] + h[k] == H1) {
                    col1i[2] = k;
                    break;
                }
            }
        }
    }
    for (int i = 0, j = 0; i < 6; i++) {
        if (col1i[0] == i || col1i[1] == i || col1i[2] == i) continue;
        col2i[j++] = i;
    }
    for (int i = 0; i < 3; i++) {
        cout << h[col1i[i]] << " ";
    }
    for (int i = 0; i < 3; i++) {
        cout << h[col2i[i]] << " ";
    }
    return 0;
}