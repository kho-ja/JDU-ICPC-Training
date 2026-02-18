// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int n, res = -1, cnt = 0;
//     cin >> n;

//     for (int i = 2; i <= 36; i++) {
//         int x = n;
//         string s;
//         do {
//             s = char(x % i + '0') + s;
//             x /= i;
//         } while (x);

//         if (s == string(s.rbegin(), s.rend())) {
//             cnt++;
//             if (res == -1) {
//                 res = i;
//                 cnt = 1;
//             }
//             else if (cnt == 2) {
//                 cout << "multiple\n";
//                 cout << res << "\n";
//                 cout << i << "\n";
//                 res = i;
//             }
//             else {
//                 res = i;
//                 cout << res << "\n";
//             }
//         }
//     }

//     if (cnt == 1) {
//         cout << "unique\n";
//         cout << res << "\n";
//     }
//     else if (cnt == 0) {
//         cout << "none\n";
//     }

// }

//* Optimized version

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s, r, res;
//     int N, n, d, cnt = 0;
//     cin >> N;

//     for (int k = 2; k <= 36; k++) {
//         s = r = "";
//         n = N;
//         do {
//             d = n % k;
//             s = char(d < 10 ? d + 48 : d + 55) + s;
//             r += char(d < 10 ? d + 48 : d + 55);
//             n /= k;
//         } while (n);

//         if (s == r) {
//             cnt++;
//             res += to_string(k) + " ";
//         }
//     }

//     cout << (cnt == 0
//                 ? "none" 
//             : cnt == 1
//                 ? "unique" 
//                 : "multiple") << "\n" << res;
// }

//* The most optimized version

#include <iostream>
#include <string>
using namespace std;

int main() {
    string res;
    int N, n, r, cnt = 0;
    cin >> N;

    for (int k = 2; k <= 36; k++) {
        r = 0;
        n = N;
        do {
            r = r * k + n % k;
            n /= k;
        } while (n);

        if (r == N) {
            cnt++;
            res += to_string(k) + " ";
        }
    }

    cout << (cnt == 0
                ? "none" 
            : cnt == 1
                ? "unique" 
                : "multiple") << "\n" << res;
}