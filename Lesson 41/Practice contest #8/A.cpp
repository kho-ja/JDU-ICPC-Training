#include <iostream>
using namespace std;

int main() {
    int n, res = 0;
    for (int i = 0; i < 4; i++) {
        cin >> n;
        res += n;
    }
    cout << res;
    return 0;
}
