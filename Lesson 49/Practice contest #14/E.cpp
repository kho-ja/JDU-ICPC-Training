#include <iostream>
#include <iomanip>
using namespace std;

double time_between(double dist, double u, double w, double A, double V) {
    // dist masofani u tezlikdan w tezlikka kelib bosib o'tishning minimal vaqti

    double need = (V * V - u * u) / (2.0 * A) + (V * V - w * w) / (2.0 * A);

    if (need <= dist) {
        // V gacha chiqib, biroz V da yurib, keyin w gacha tushish mumkin
        return (V - u) / A + (V - w) / A + (dist - need) / V;
    } else {
        // V gacha yetib bo'lmaydi, biror peak tezlikkacha chiqib, keyin tushamiz
        double peak = sqrt(A * dist + (u * u + w * w) / 2.0);
        return (peak - u) / A + (peak - w) / A;
    }
}

double time_after_radar(double dist, double u, double A, double V) {
    // Oxirgi tezlik ahamiyatsiz, shuning uchun faqat tezlashamiz

    double need = (V * V - u * u) / (2.0 * A);

    if (need <= dist) {
        return (V - u) / A + (dist - need) / V;
    } else {
        double final_speed = sqrt(u * u + 2.0 * A * dist);
        return (final_speed - u) / A;
    }
}

int main() {
    double A, V;
    cin >> A >> V;

    double L, R, K;
    cin >> L >> R >> K;

    double S = min({K, V, sqrt(2.0 * A * R)});

    double ans = 0;
    ans += time_between(R, 0, S, A, V);
    ans += time_after_radar(L - R, S, A, V);

    cout << fixed << setprecision(6) << ans << '\n';

    return 0;
}