#include <iostream>
using namespace std;

int a[1001];

int get(int x) {
    return a[x];
}

void update(int l, int r, int x) {
    for (int i = l; i <= r; i++) a[i] = x;
}

void add(int l, int r, int x) {
    for (int i = l; i <= r; i++) a[i] += x;
}

int rsq(int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) sum += a[i];
    return sum;
}

int rmq(int l, int r) {
    int min_val = a[l];
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < min_val) min_val = a[i];
    }
    return min_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cin >> k;
    for (int i = 0; i < k; i++) {
        string func;
        cin >> func;
        if (func == "get") {
            int x;
            cin >> x;
            cout << get(x) << endl;
        }
        else if (func == "update") {
            int l, r, x;
            cin >> l >> r >> x;
            update(l, r, x);
        }
        else if (func == "add") {
            int l, r, x;
            cin >> l >> r >> x;
            add(l, r, x);
        }
        else if (func == "rsq") {
            int l, r;
            cin >> l >> r;
            cout << rsq(l, r) << endl;
        }
        else if (func == "rmq") {
            int l, r;
            cin >> l >> r;
            cout << rmq(l, r) << endl;
        }
    }
}