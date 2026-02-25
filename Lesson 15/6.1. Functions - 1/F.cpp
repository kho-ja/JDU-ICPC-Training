#include <iostream>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    Point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    cout << fixed << abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0 << "\n";
    return 0;
}