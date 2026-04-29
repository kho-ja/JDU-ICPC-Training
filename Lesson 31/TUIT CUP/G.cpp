#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A;
    vector<int> R;
    int res = 0;
    for (int i = 0; i < 3; i++) {
        int a, r, n;
        cin >> a >> r >> n;
        A.push_back(a);
        R.push_back(r);
        int N = n;
        bool exists = false;
        while (n--) {
            int num = a + r * (N - n - 1);
            for (int i = 0; i < A.size(); i++)
                if (num % A[i] == R[i]) exists = true;
        }
        if (!exists) res++;
    }
    cout << res;
    return 0;
}