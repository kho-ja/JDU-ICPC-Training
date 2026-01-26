// #include <iostream>
// using namespace std;

// int main()
// {
//     int a, b, c, max, min;
//     cin >> a >> b >> c;
//     if (a > b) {
//         if (a > c) {
//             max = a;
//         } else {
//             max = c;
//         }
//         if (b > c) {
//             min = c;
//         } else {
//             min = b;
//         }
//     } else {
//         if (b > c) {
//             max = b;
//         } else {
//             max = c;
//         }
//         if (a > c) {
//             min = c;
//         } else {
//             min = a;
//         }
//     }
//     cout << max - min << endl;
// }

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);

    cout << c - a << endl;
}