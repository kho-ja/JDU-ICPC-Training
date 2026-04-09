#include <iostream>
#include <vector>
using namespace std;

int cost, n, A[15];
vector<int> curr_sol, solution, curr_cnt(15, 2);

void brute_force(int i, long long curr_sum) {
    if (i == n) {
        if (curr_sum == cost && (solution.empty() || curr_sol.size() < solution.size())) {
            solution = curr_sol;
        }
    }
    else {
        if (curr_cnt[i]) {
            curr_cnt[i]--;
            curr_sol.push_back(i);
            brute_force(i, curr_sum + A[i]);
            curr_sol.pop_back();
            curr_cnt[i]++;
        }
        brute_force(i + 1, curr_sum);
    }

}

int main() {
    long long sum = 0;
    cin >> cost >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i] * 2;
    }

    if (sum < cost) {
        cout << -1;
        return 0;
    }

    brute_force(0, 0);

    if (solution.empty()) {
        cout << 0;
    }
    else {
        cout << solution.size() << " ";
    }

    return 0;
}