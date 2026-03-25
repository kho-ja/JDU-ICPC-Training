#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> a(4);
    for (string& i : a) cin >> i;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 1][j + 1] && a[i][j] == a[i][j + 1]) {
                cout << "No";
                return 0;
            }
    }
    cout << "Yes";
    return 0;
}