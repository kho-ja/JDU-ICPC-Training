#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int daysMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int dayOfYear(int d, int m) {
    int days = d;
    for (int i = 1;i < m;i++) days += daysMonth[i];
    return days;
}

int workMinute(int d, int m, int h, int mi) {
    int day = dayOfYear(d, m);

    int minutes = (day - 1) * 480; // kun boshigacha ish minutlari

    int cur = h * 60 + mi;

    int start = 10 * 60;
    int end = 18 * 60;

    if (cur < start) cur = start;
    if (cur > end) cur = end;

    minutes += cur - start;

    return minutes;
}

int main() {

    int K;
    cin >> K;

    vector<int> t(K);

    for (int i = 0;i < K;i++) {
        int d, m, h, mi;
        char c;

        cin >> d >> c >> m >> c >> h >> c >> mi;

        t[i] = workMinute(d, m, h, mi);
    }

    sort(t.begin(), t.end());

    long long sum = 0;

    for (int i = 1;i < K;i += 2)
        sum += t[i] - t[i - 1] + 1;

    long long h = sum / 60;
    long long m = sum % 60;

    cout << h << ":" << setw(2) << setfill('0') << m;
}