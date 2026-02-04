#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    do {
        cin >> n;
        cnt+=n;
    } while (n != 0);
    cout << cnt;
}