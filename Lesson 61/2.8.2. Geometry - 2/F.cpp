#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define point pair<int,int>
#define x first
#define y second
#define sqr(x) 1ll*(x)*(x)

int main() {
    int n, cntx = 0, cnty = 0;
    cin >> n;
    vector<point> p(n);
    for (auto &[x, y]:p) cin >> x >> y;

    set<point> st(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        map<long long, int> mp;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            long long dist2 = sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y);
            cntx += mp[dist2]++;
            cnty += st.count({2 * p[i].x - p[j].x, 2 * p[i].y - p[j].y});
        }
    }

    cout << cntx - cnty / 2;
    return 0;
}
