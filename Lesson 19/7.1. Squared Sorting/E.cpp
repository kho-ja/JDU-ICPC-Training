#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K;
    cin >> K;

    vector<int> cost(K);

    for (int i = 0; i < K; i++) {
        int g;
        cin >> g;
        cost[i] = g / 2 + 1;
    }

    sort(cost.begin(), cost.end());

    int needGroups = K / 2 + 1;
    int result = 0;

    for (int i = 0; i < needGroups; i++) {
        result += cost[i];
    }

    cout << result;

    return 0;
}