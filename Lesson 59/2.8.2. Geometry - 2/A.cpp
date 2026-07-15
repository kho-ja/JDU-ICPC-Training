#include <ios>
#include <iostream>
#include <istream>
#include <vector>
using namespace std;

struct point {
    int x, y;
};

double area(point A, point B) {
    return A.x*B.y - B.x*A.y;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<point> a(n);
    for (auto &X: a) cin >> X.x >> X.y;

    double total = area(a[n-1], a[0]);
    for (int i = 1; i < n; i++) total += area(a[i - 1], a[i]);
    cout.precision(1);
    cout << fixed << abs(total) / 2;
    return 0;
}
