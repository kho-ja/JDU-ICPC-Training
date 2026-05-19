#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, h, m, s;
    ll sum = 0;
    char c;
    cin >> n;
    vector<int> a(n), cnt(46800);
    for (int i = 0; i < n; i++) {
        cin >> h >> c >> m >> c >> s;
        int v = h * 3600 + m * 60 + s;
        cnt[v]++;
        sum += v == 3600 ? 0 : 46800 - v;
    }

    ll resmin = sum, restime = 3600;
    for (int i = 3601; i < 46800; i++) {
        sum += n;
        sum -= cnt[i] * 43200LL;
        if (sum < resmin) {
            resmin = sum;
            restime = i;
        }
    }

    printf("%d:%02d:%02d\n", (int)restime / 3600, (int)(restime % 3600) / 60, (int)(restime % 3600) % 60);
    return 0;
}
