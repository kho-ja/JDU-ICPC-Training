// #include <iostream>
// using namespace std;

// void heap_sort(int a[], int n) {
//     auto heap = [&](int i) {
//         int mx_id = i;
//         while (true) {
//             if (2 * i + 1 < n && a[2 * i + 1] > a[mx_id]) mx_id = 2 * i + 1;
//             if (2 * i + 2 < n && a[2 * i + 2] > a[mx_id]) mx_id = 2 * i + 2;
//             if (mx_id == i) break;
//             else {
//                 swap(a[i], a[mx_id]);
//                 i = mx_id;
//             }
//         }
//         };
//     for (int i = (n - 1) / 2; i >= 0; i--) heap(i);
//     while (n > 1) {
//         swap(a[0], a[--n]);
//         heap(0);
//     }
// };

// int main() {
//     int n;
//     cin >> n;
//     int* a = new int[n];
//     for (int i = 0; i < n; i++) cin >> a[i];

//     heap_sort(a, n);

//     for (int i = 0; i < n; i++) cout << a[i] << " ";
//     cout << endl;
// }

//* Count inversions in an array using merge sort
// #include <iostream>
// #include <algorithm>
// using namespace std;

// long long inv_count(int a[], int L, int R) {
//     long long res = 0;

//     if (R - L > 1) {
//         int M = (L + R) / 2;
//         res += inv_count(a, L, M) + inv_count(a, M, R);
//         for (int i = L, j = M; i < M; i++) {
//             while (j < R && a[i] > a[j]) j++;
//             res += j - M;
//         }
//         inplace_merge(a + L, a + M, a + R);
//     }
//     return res;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     int* a = new int[n];
//     for (int i = 0; i < n; i++) cin >> a[i];

//     cout << inv_count(a, 0, n - 1);
// }

#include <iostream>
using namespace std;

int main() {
    cout << "In this Lesson we learned Sorting algorithms. But we did not solve anything. but we have to do it even though we are not doing.";
    return 0;
}