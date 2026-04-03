#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<bool>> A(N + 2, vector<bool>(M + 2, false));
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        A[x][y] = true;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i][j]) {
                cout << "*";
            }
            else {
                int cnt = A[i][j] + A[i - 1][j] + A[i + 1][j] + A[i][j - 1] + A[i][j + 1] + A[i - 1][j - 1] + A[i - 1][j + 1] + A[i + 1][j - 1] + A[i + 1][j + 1];
                if (cnt) {
                    cout << cnt;
                }
                else {
                    cout << ".";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}