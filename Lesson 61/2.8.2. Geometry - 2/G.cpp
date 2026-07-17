#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define sqr(x) (x)*(x)

struct point {
    double x, y;
    friend istream &operator>>(istream &is, point &p) {
        is >> p.x >> p.y;
        return is;
    }
};

point outer_circle_center_for_triangle(point A, point B, point C) {
    auto mysqr = [](point A) { return sqr(A.x) + sqr(A.y); };
    return {
        - (A.y * (mysqr(B) - mysqr(C)) + B.y * (mysqr(C) - mysqr(A)) + C.y * (mysqr(A) - mysqr(B))) / (2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y))),
        (A.x * (mysqr(B) - mysqr(C)) + B.x * (mysqr(C) - mysqr(A)) + C.x * (mysqr(A) - mysqr(B))) / (2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)))
    };
}

double area(point A, point B, point C) {
    return abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0;
}

double length(point A, point B) {
    return hypot(A.x - B.x, A.y - B.y);
}


int main() {
    int n;
    double eps = 1e-9;
    cin >> n;
    vector<point> p(n);
    vector<int> list1, list2;
    for (auto &x:p) cin >> x;

    auto solve = [&](point A, point B, point C)->bool {
        double S = area(A, B, C);
        if (S <= eps) return false;
        point O = outer_circle_center_for_triangle(A, B, C);
        double R = length(O, A);
        list1.clear();
        list2.clear();
        for (int i = 0; i < n; i++) {
            if (abs(length(O, p[i]) - R) < eps) list1.push_back(i);
            else list2.push_back(i);
        }
        if (list2.size() < 3) {
            if (list2.empty()) list2.push_back(0);
            return true;
        }

        S = area(p[list1[0]], p[list2[1]], p[list2[2]]);
        if (S <= eps) return false;
        O = outer_circle_center_for_triangle(p[list1[0]], p[list2[1]], p[list2[2]]);
        R = length(O, p[list1[0]]);

        for (int i = 3; i < list2.size(); i++) {
            if (abs(length(O, p[list2[i]]) - R) < eps) return false;
        }
        for (int i : list1) {
            double dist = length(O, p[i]);
            if (abs(dist - R) < eps) list2.push_back(i);
        }
        return true;
    };

    if (n == 1) {
        cout << "1\n1";
    } else if (n == 2) {
        cout << "1\n2";
    } else if (n == 3) {
        cout << "1 2\n3";
    } else if (n == 4) {
        cout << "4 1\n2 3 4";
    } else {
        for (int i = 0; i < 5; i++)
            for (int j = i + 1; j < 5; j++)
                for (int k = j + 1; k < 5; k++)
                    if (solve(p[i], p[j], p[k]))
                        goto finish;
        finish:
        for (int x: list1) cout << x + 1 << ' ';
        cout << '\n';
        for (int x: list2) cout << x + 1 << ' ';
        cout << '\n';
    }
    return 0;
}
