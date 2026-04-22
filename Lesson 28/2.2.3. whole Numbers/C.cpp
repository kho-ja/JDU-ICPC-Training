#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, k, product = 1;
    string s;
    cin >> n >> s;

    k = s.size();
    for (int i = k + 1; i <= n; i += k)
        product *= i;

    cout << product;
    return 0;
}