#include <iostream>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    int n;
    cin >> n;
    Point a[1000];

    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    long long mnDist = 1e18, mxDist = -1;
    int mn1 = 0, mn2 = 1, mx1 = 0, mx2 = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dx = a[i].x - a[j].x;
            long long dy = a[i].y - a[j].y;
            long long dist2 = dx * dx + dy * dy;

            if (dist2 < mnDist) {
                mnDist = dist2;
                mn1 = i;
                mn2 = j;
            }
            if (dist2 > mxDist) {
                mxDist = dist2;
                mx1 = i;
                mx2 = j;
            }
        }
    }

    cout << mn1 + 1 << " " << mn2 + 1 << endl;
    cout << mx1 + 1 << " " << mx2 + 1 << endl;

    return 0;
}