#include <iostream>
using namespace std;

int sum_of_digits(int k) {
    return k / 100 + (k / 10) % 10 + k % 10;
}

bool is_happy(int k) {
    return sum_of_digits(k / 1000) == sum_of_digits(k % 1000);
}

bool is_neighbor_happy(int k) {
    return is_happy(k - 1) || is_happy(k + 1);
}

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        cout << (is_neighbor_happy(k) ? "Yes" : "No") << endl;
    }
    return 0;
}