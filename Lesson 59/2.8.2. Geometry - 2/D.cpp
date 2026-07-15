#include <algorithm>
#include <iostream>
#include <istream>
#include <vector>
using namespace std;

struct point {
    int x, y;
};

int area(point A, point B, point C) {
    return A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y);
}

istream& operator>>(istream &is, point &A) {
    is >> A.x >> A.y;
    return is;
}

bool operator<(point a, point b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}

int orientation (point A, point B, point C) {
    int s = area(A, B, C);
    return s > 0 ? 1 : s < 0 ? -1 : 0;
}

vector<point> convex_hull(vector<point> a) {
    sort(a.begin(), a.end());
    vector<point> up, down;
    for (point &p:a) {
        while(up.size() > 1 && orientation(up[up.size() - 2], up[up.size() - 1], p) != -1)
            up.pop_back();
        up.push_back(p);

        while(down.size() > 1 && orientation(down[down.size() - 2], down[down.size() - 1], p) != 1)
            down.pop_back();
        down.push_back(p);
    }
    for (int i = (int)up.size() - 2; i > 0; --i)
        down.push_back(up[i]);
    return down;
}

int area(vector<point> a) {
    auto get = [](point a, point b) {
        return a.x * b.y - b.x * a.y;
    };
    int s = get(a.back(), a[0]);
    for (int i = 1; i < a.size(); i++) s+= get(a[i - 1], a[i]);
    return (s + 1) / 2;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<point> a(n);
    for (auto &x:a) cin >> x;
    cout << area(convex_hull(a));
    return 0;
}
