#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
using namespace std;
#define sqr(x) ((x) * (x))

const double EPS = 1e-6;

struct point {
    double x, y;
};

struct line {
    double a, b, c;
};

double length(point A, point B) {
    return hypot(A.x - B.x, A.y - B.y);
}

double height(point A, point B, point C) {
    return abs(A.x * (B.y - C. y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / length(A, B);
}

line build_line(point A, point B) {
    line l;
    if (abs(A.y - B.y) <= EPS) {
        l.a = 0;
        l.b = 1;
        l.c = A.y;
    } else {
        l.a = 1;
        l.b = (B.x - A.x) / (A.y - B.y);
        l.c = A.x + l.b * A.y;
    }
    return l;
}

line bisect(point A, point B, point C) {
    double b = length(A, C), c = length(A, B);
    B.x = (B.x - A.x) * b / c + A.x;
    B.y = (B.y - A.y) * b / c + A.y;
    point D;
    D.x = (B.x + C.x) / 2;
    D.y = (B.y + C.y) / 2;
    return build_line(A, D);
}

point intersection(line l1, line l2) {
    return {
        (l1.c * l2.b - l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b),
        (l1.c * l2.a - l2.c * l1.a) / (l1.b * l2.a - l2.b * l1.a)
    };
}

istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
}

ostream& operator<<(ostream& os, point p) {
    os << p.x << " " << p.y;
    return os;
}

int main() {
    int n;
    cin >> n;
    vector<point> points(n);
    for (point& p : points)
        cin >> p;

    line l1 = bisect(points[0], points[1], points[n-1]);
    line l2 = bisect(points[1], points[0], points[2]);

    point O = intersection(l1, l2);

    double R = height(points[0], points[n-1], O);
    bool ok = true;

    for (int i = 1; i < n; i++) {
        if (abs(height(points[i-1], points[i], O) - R) > EPS) {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << "YES\n" << fixed << O << " " << R << "\n";
    else
        cout << "NO\n";

    return 0;
}
