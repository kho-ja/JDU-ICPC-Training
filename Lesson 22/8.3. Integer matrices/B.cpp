#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    bool *a = new bool[x*y];
    int n;
    cin >> n;
    while (n--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (i >= x1 && i <= x2 && j >= y1 && j <= y2) {
                    a[i * y + j] = true;
                }
            }
        }
    }
    for (int i = 0; i < x * y; i++) {
        cout << a[i] << " ";
    }
    return 0;
}