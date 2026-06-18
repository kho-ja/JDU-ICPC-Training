#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    cout << n * (n + 1) * (n + 2) / 6 + (n*(n+1)*(2*n+1) / 6 - (n + 1) / 2) / 4;
    return 0;
}
