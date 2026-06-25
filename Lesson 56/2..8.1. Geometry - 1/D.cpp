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
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

int main() {
    point p;
    cin >> p.x >> p.y;
    double r;
    cin >> r;
    int n;
    cin >> n;
    vector<point> points;
    for (int i = 0; i < n; i++) {
        point a;
        cin >> a.x >> a.y;
        if (dist(p, a) <= r * r) points.push_back(a);
    }

    int mx = 0;
    for (point a : points) {
        int cnt = 0;
        for (point b : points) {
            if (area(a, b, p) >= 0) cnt++;
        }
        if (cnt > mx) mx = cnt;
    }
    cout << mx << endl;
    
    return 0;
}
