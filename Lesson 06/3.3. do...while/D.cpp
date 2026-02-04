#include <iostream>
using namespace std;

int main() {
    int n, cnt = -1;
    do {
        cin >> n;
        if (n % 2 == 0) cnt++;
    } while (n != 0);
    cout << cnt;
}