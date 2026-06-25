#include <algorithm>
#include <iostream>
using namespace std;

struct point {
    int x, y;
};

int dist(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    point p[3];
    for (point& i : p)
        cin >> i.x >> i.y;
    while(dist(p[0], p[2]) != dist(p[1], p[2]) + dist(p[1], p[0])) rotate(p, p+1, p+3);
    cout << p[0].x + p[2].x - p[1].x << " " << p[0].y + p[2].y - p[1].y << endl;
    return 0;
}
