#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> a(N);
    long long S = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        S += a[i];
    }

    sort(a.begin(), a.end());

    long long sum_player = 0;
    for (int i = N / 2; i < N; i++) {
        sum_player += a[i];
    }

    long long win = 2 * sum_player - S;

    cout << win;

    return 0;
}