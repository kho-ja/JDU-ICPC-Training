#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    vector<int> A(N);
    for (auto &a: A) cin >> a;
    sort(A.rbegin(), A.rend());

    int i = 0;
    while (K > 0 && i < A.size()) {
        K -= A[i];
        i++;
    }
    if (K > 0) cout << A.size() << endl;
    else cout << i << endl;

    return 0;
}
