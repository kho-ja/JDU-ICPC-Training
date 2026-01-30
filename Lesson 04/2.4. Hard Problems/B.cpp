#include <iostream>
using namespace std;

int main()
{
    int K, W, a1, b1, a2, b2, a3, b3;
    cin >> K >> W >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    cout << (a1 <= W && b1 >= K ||
                     a2 <= W && b2 >= K ||
                     a3 <= W && b3 >= K ||
                     (a1 + a2) <= W && (b1 + b2) >= K ||
                     (a1 + a3) <= W && (b1 + b3) >= K ||
                     (a2 + a3) <= W && (b2 + b3) >= K ||
                     (a1 + a2 + a3) <= W && (b1 + b2 + b3) >= K
                 ? "YES"
                 : "NO");
}