#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, oddcnt = 0, evencnt = 0;
        cin >> N;
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                if (i % 2) oddcnt++;
                else evencnt++;
                if (i != N / i) {
                    if ((N / i) % 2) oddcnt++;
                    else evencnt++;
                }
            }
        }
        if (oddcnt == evencnt) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}
