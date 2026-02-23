#include <iostream>
using namespace std;

char first[100001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;


    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        first[x] = 1;
    }

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        first[x] |= 2;
    }

    for (int i = 0; i <= 100000; i++) {
        if (first[i] == 3) {
            cout << i << " ";
        }
    }

    cout << "\n";
    return 0;
}