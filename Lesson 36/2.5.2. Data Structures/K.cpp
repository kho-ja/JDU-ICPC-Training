#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct seat {
    priority_queue<int, vector<int>, greater<>> free;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy;
    seat (int m) {
        for (int i = 1; i <= m; i++) free.push(i);
    }
    int put(int L, int R) {
        while (!busy.empty() && busy.top().first <= L) {
            free.push(busy.top().second);
            busy.pop();
        }
        if (free.empty()) return 0;
        int seat = free.top();
        free.pop();
        busy.push({R, seat});
        return seat;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(k);

    for (auto &[L, R]: a) cin >> L >> R;

    stable_sort(a.begin(), a.end(), [&](auto &x, auto &y) {
        return x.first < y.first;
    });

    seat sit(m), stand(m);
    vector<int> b(m+1);
    auto put = [&](int L, int R) {
        if (sit.put(L, R) == 0)
            b[stand.put(L, R)] += R - L;
    };

    put(1, n);
    for (auto &[L, R]: a) put(L, R);

    auto me = min_element(b.begin()+1,b.end());

    cout << *me << ' ' << me - b.begin();

    return 0;
}
