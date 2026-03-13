#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> a(N);
    for (auto& x : a) {
        string h, m, s;
        cin >> h >> m >> s;
        x = (stoll(h) * 3600 + stoll(m) * 60 + stoll(s));
    }

    sort(a.begin(), a.end());

    for (const auto& x : a) {
        long long h = x / 3600;
        long long m = (x % 3600) / 60;
        long long s = x % 60;
        printf("%d %d %d\n", h, m, s);
    }

    return 0;
}