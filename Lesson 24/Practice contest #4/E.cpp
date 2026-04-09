
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) cin >> a[i];

    // Precompute suffix min/max
    vector<int> res;
    int seg_min = 1e9, seg_max = -1e9;
    vector<bool> seen(N + 2, false);
    int l = 1;
    for (int i = 1; i <= N; ++i) {
        seg_min = min(seg_min, a[i]);
        seg_max = max(seg_max, a[i]);
        seen[a[i]] = true;
        int len = i - l + 1;
        // Check if current segment [l, i] is a permutation of 1..len
        bool is_perm = (seg_min == 1 && seg_max == len);
        for (int v = 1; is_perm && v <= len; ++v) {
            if (!seen[v]) is_perm = false;
        }
        if (is_perm) {
            res.push_back(i);
            // Reset for next segment
            seg_min = 1e9;
            seg_max = -1e9;
            for (int v = 1; v <= len; ++v) seen[v] = false;
            l = i + 1;
        }
    }
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << '\n';
    return 0;
}