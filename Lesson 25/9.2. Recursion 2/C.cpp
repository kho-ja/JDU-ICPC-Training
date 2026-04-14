#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> solution;

void calculate(int n) {
    if (n <= 8 - solution.size()) {
        while (n--) solution.push_back(1);
        for (auto x : solution) cout << x << " ";
        exit(0);
        return;
    }
    if (solution.size() >= 8) return;
    int cb = cbrt(n);
    for (int i = cb; i >= 1; i--) {
        solution.push_back(i);
        calculate(n - i * i * i);
        solution.pop_back();
    }
    return;
}

int main() {
    int n;
    cin >> n;
    calculate(n);
    cout << "IMPOSSIBLE" << endl;
    return 0;
}