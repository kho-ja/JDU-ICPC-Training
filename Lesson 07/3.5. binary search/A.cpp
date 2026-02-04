#include <iostream>
using namespace std;

int main() {
    long long n;
    int res = 0;
    cin >> n;
    while (n > 1) {
        res++;
        n -= n / 2;
    }
    cout << res;
}