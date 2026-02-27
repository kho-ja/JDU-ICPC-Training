#include <iostream>
using namespace std;

struct Point {
    long long x, y;
};

long long area(Point A, Point B, Point C) {
    return (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

int main() {
    Point A, B, C, P;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> P.x >> P.y;
    long long ABP = area(A, B, P);
    long long BCP = area(B, C, P);
    long long CAP = area(C, A, P);
    cout << ((ABP >= 0 && BCP >= 0 && CAP >= 0) || (ABP <= 0 && BCP <= 0 && CAP <= 0) ? "In" : "Out");
    return 0;
}