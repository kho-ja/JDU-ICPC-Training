#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int* X = new int[m], * Y = new int[m], * x = new int[n], * y = new int[n];
    for (int i = 0; i < m; i++) cin >> X[i] >> Y[i];
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 1; j < m; j++)
            if (abs(X[res] - x[j]) + abs(Y[res] - y[j]) > abs(x[j] - X[i]) + abs(y[j] - Y[i]))
                res = j;
        cout << res + 1 << " \n";
    }
    return 0;
}
