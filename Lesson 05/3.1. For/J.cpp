#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int best = 0;
    int current = 0;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;

        if (t > 0) {
            current++;
            if (current > best)
                best = current;
        } else {
            current = 0;
        }
    }

    cout << best;
}
