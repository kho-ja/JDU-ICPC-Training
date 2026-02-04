#include <iostream>
using namespace std;

int main() {
    int n, cnt = -1, sum = 0;
    do {
        cin >> n;
        cnt++;
        sum+=n;
    } while (n != 0);
    cout << 1.0*sum/cnt;
}