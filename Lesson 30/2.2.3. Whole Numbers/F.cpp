#include <iostream>
using namespace std;

long long arr[] = { 6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128 };

int main() {
    long long n, m;
    cin >> n >> m;
    bool absent = true;
    for (auto x : arr)
        if (x >= n && x <= m) {
            cout << x << " ";
            absent = false;
        }
    if (absent) cout << "Absent";
    return 0;
}