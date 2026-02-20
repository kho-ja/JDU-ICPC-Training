#include <iostream>
using namespace std;

int main() {
    int n, l, r, id;
    cin >> n;
    int a[1001];

    for (int i = 1; i <= n; i++) cin >> a[i];

    cin >> l >> r;
    id = l;

    for (int i = l + 1; i <= r; i++)
        if (a[i] > a[id]) id = i;

    cout << a[id] << " " << id;
}