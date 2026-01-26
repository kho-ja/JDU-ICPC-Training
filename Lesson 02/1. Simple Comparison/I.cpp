// #include <iostream>
// using namespace std;

// int main() {
//     int A1, A2, A3, B1, B2, B3, total, max = 0;
//     cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3;

//     total = A1*B1 + A2*B2 + A3*B3;
//     if (total > max) max = total;
    
//     total = A1*B1 + A3*B2 + A2*B3;
//     if (total > max) max = total;

//     total = A2*B1 + A1*B2 + A3*B3;
//     if (total > max) max = total;

//     total = A2*B1 + A3*B2 + A1*B3;
//     if (total > max) max = total;

//     total = A3*B1 + A1*B2 + A2*B3;
//     if (total > max) max = total;

//     total = A3*B1 + A2*B2 + A1*B3;
//     if (total > max) max = total;

//     cout << max;
// }

#include <iostream>
using namespace std;

int main ()
{
    int A1, A2, A3, B1, B2, B3;
    cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3;

    if (A1 > A2) swap(A1, A2);
    if (A1 > A3) swap(A1, A3);
    if (A2 > A3) swap(A2, A3);

    if (B1 > B2) swap(B1, B2);
    if (B1 > B3) swap(B1, B3);
    if (B2 > B3) swap(B3, B2);

    cout << A1*B1 + A2*B2 + A3*B3;
}