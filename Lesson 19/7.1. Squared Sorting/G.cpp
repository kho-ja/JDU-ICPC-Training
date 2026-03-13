#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getDigits(long long x) {
    vector<int> d;
    if (x == 0) d.push_back(0);
    while (x) {
        d.push_back(x % 10);
        x /= 10;
    }
    return d;
}

long long makeMax(vector<int> d) {
    sort(d.begin(), d.end(), greater<int>());
    long long x = 0;
    for (int v : d) x = x * 10 + v;
    return x;
}

long long makeMin(vector<int> d) {
    sort(d.begin(), d.end());

    if (d[0] == 0) {
        for (int i = 1; i < d.size(); i++) {
            if (d[i] != 0) {
                swap(d[0], d[i]);
                break;
            }
        }
    }

    long long x = 0;
    for (int v : d) x = x * 10 + v;
    return x;
}

int main() {
    long long a, b;
    cin >> a >> b;

    vector<int> da = getDigits(llabs(a));
    vector<int> db = getDigits(llabs(b));

    long long A, B;

    if (a >= 0) A = makeMax(da);
    else A = -makeMin(da);

    if (b >= 0) B = makeMin(db);
    else B = -makeMax(db);

    cout << A - B;
}