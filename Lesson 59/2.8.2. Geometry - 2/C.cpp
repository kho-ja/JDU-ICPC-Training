#include <iostream>
#include <istream>
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

int orientation (point A, point B, point C) {
    int s = area(A, B, C);
    return s > 0 ? 1 : s < 0 ? -1 : 0;
}

bool is_intersects(point A, point B, point C, point D) {
    int ABC = orientation(A, B, C);
    int ABD = orientation(A, B, D);
    int CDA = orientation(C, D, A);
    int CDB = orientation(C, D, B);

    auto check = [](point A, point B, point C) {
        return min(A.x, B.x) <= C.x && max(A.x, B.x) >= C.x && min(A.y, B.y) <= C.y && max(A.y, B.y) >= C.y;
    };

    if (ABC == 0 && check(A, B, C)) return true;
    if (ABD == 0 && check(A, B, D)) return true;
    if (CDA == 0 && check(C, D, A)) return true;
    if (CDB == 0 && check(C, D, B)) return true;
    return CDA * CDB == -1 && ABC * ABD == -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    point A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << (is_intersects(A, B, C, D) ? "Yes" : "No");
    return 0;
}
