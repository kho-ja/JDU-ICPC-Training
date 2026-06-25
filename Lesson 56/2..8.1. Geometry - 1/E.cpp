#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

struct point {
    double x, y;
};

int dist(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double area(point a, point b, point c) {
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

point intersection(int a1, int b1, int c1, int a2, int b2, int c2) {
    point p;
    p.x = 1.0 * (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
    p.y = 1.0 * (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
    return p;
}

int main() {
    int a1, b1, c1, a2, b2, c2, a3, b3, c3;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> a3 >> b3 >> c3;
    point a = intersection(a1, b1, c1, a2, b2, c2);
    point b = intersection(a1, b1, c1, a3, b3, c3);
    point c = intersection(a2, b2, c2, a3, b3, c3);
    cout << fixed;
    cout << area(a, b, c) / 2.0 << endl;
    return 0;
}
