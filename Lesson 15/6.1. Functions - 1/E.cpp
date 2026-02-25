#include <iostream>
#define sqr(x) (x)*(x)
using namespace std;

struct Point {
    int x, y;
};

int Side(Point A, Point B) {
    return sqr(A.x - B.x) + sqr(A.y - B.y);
}

int main() {
    Point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    int a2 = Side(B, C);
    int b2 = Side(A, C);
    int c2 = Side(A, B);

    cout << (a2 == b2 + c2 || b2 == a2 + c2 || c2 == a2 + b2 ? "Yes" : "No") << "\n";
    return 0;
}