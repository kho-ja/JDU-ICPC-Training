#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    double G;
    cin >> G;

    sort(a.begin(), a.end());

    for (int i = 0; i < N; i++) {
        if (a[i] > G) {
            G = (G + a[i]) / 2.0;
        }
    }

    cout << fixed << setprecision(6) << G;

    return 0;
}