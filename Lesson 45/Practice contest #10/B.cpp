#include <iostream>
using namespace std;

int N, A, B, X, Y;
int res = 2e9;

int main() {
    cin >> N >> A >> B >> X >> Y;

    int i = (N + A - 1) / A, currA, currB, curr;
    while (i != -1) {
        currA = i * A;
        currB = 0;
        if (currA < N) {
            currB = ((N - currA + B - 1) / B);
        }
        curr = i * X + currB * Y;
        res = min(res, curr);
        i--;
    }
    cout << res;
    
    return 0;
}
