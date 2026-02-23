#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    int first[100001] = { 0 };

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        first[x] = 1;
    }

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        if (first[x] == 1) first[x] = 2;
    }

    for (int i = 0; i <= 100000; i++) {
        if (first[i] == 2) {
            cout << i << " ";
        }
    }

    cout << "\n";
    return 0;
}