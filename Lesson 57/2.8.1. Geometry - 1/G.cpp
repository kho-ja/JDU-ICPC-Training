#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;
#define sqr(x) ((x) * (x))

struct point {
    double x, y;
};

double length(point A, point B) {
    return hypot(A.x - B.x, A.y - B.y);
}

double height(point A, point B, point C) {
    return abs(A.x * (B.y - C. y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / length(A, B);
}

point inner_circle_center_for_triangle(point A, point B, point C) {
    double a = length(B, C), b = length(A, C), c = length(A, B);
    return {
        (A.x * a + B.x * b + C.x * c) / (a + b + c),
        (A.y * a + B.y * b + C.y * c) / (a + b + c)
    };
}

point outer_circle_center_for_triangle(point A, point B, point C) {
    auto mysqr = [](point A) { return sqr(A.x) + sqr(A.y); };
    return {
        - (A.y * (mysqr(B) - mysqr(C)) + B.y * (mysqr(C) - mysqr(A)) + C.y * (mysqr(A) - mysqr(B))) / (2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y))),
        (A.x * (mysqr(B) - mysqr(C)) + B.x * (mysqr(C) - mysqr(A)) + C.x * (mysqr(A) - mysqr(B))) / (2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)))
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
    point A, B, C;
    string s;
    cin >> A >> B >> C >> s;
    if (s == "In") {
        point P = inner_circle_center_for_triangle(A, B, C);
        cout << P << " " << height(A, B, P);
    } else {
        point P = outer_circle_center_for_triangle(A, B, C);
        cout << P << " " << length(A, P);
    }
    return 0;
}
