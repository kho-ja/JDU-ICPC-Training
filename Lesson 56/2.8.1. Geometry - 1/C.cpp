#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

struct point {
    int x, y;
};

int dist(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int area(point a, point b, point c) {
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

int main() {
    point p;
    cin >> p.x >> p.y;
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        point a, b, c;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        int s1 = area(p, a, b), s2 = area(p, b, c), s3 = area(p, c, a);
        if (area(a,b,c) == s1 + s2 + s3 && s1 > 0 && s2 > 0 && s3 > 0) res.push_back(i);
    }
    cout << res.size() << endl;
    for (int i : res) cout << i + 1 << " ";
    return 0;
}
