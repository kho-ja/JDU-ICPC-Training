#include <iostream>
using namespace std;
using ll = long long;

ll n;

ll get(ll num = 0) {
    if (num <= n) return 1 + get(num * 10 + 5) + get(num * 10 + 7);
    else return 0;
}

int main() {
    cin >> n;
    cout << get() - 1;
    return 0;
}
