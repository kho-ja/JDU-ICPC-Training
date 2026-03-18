#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int sum;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Student> a(n);

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> a[i].name >> x >> y >> z;
        a[i].sum = x + y + z;
    }

    sort(a.begin(), a.end(), [](const Student& A, const Student& B) {
        if (A.sum != B.sum)
            return A.sum > B.sum;
        return A.name > B.name;
        });

    cout << a[m - 1].name << " " << a[m - 1].sum << "\n";
}