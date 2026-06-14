#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int fives = 0, twos = 0;
    for (int i = n; i <= m; i++) {
        int x = i;
        while (x % 5 == 0) {
            x /= 5;
            fives++;
        }
        while (x % 2 == 0) {
            x /= 2;
            twos++;
        }
    }
    cout << min(fives, twos);
}
