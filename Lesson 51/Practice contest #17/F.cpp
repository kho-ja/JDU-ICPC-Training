#include <iostream>
using namespace std;

int main() {
    int L, R, cnt = 0;
    cin >> L >> R;
    for (int i = L; i <= R; i++) {
        int x = i;
        bool ok = true;
        while (x) {
            int num = x % 10;
            if (num == 0 || i % num != 0) {
                ok = false;
                break;
            }
            x /= 10;
        }
        if (ok) cnt++;
    }
    cout << cnt;
}
