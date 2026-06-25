#include <cmath>
#include <iostream>
#include <istream>
using namespace std;

struct point {
    double x, y;
};

istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
}

double height(point A, point B, point C) {
    return abs(A.x * (B.y - C. y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / hypot((A.x - B.x), (A.y - B.y));
}

int main() {
    point A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << fixed << min(height(A, B, D), min(height(A, C, D), height(B, C, D))) << endl;
    return 0;
}
