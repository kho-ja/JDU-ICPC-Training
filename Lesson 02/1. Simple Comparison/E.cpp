#include <iostream>
using namespace std;

int main()
{
    int a, b, a1, b1, a2, b2, a3, b3, sumA = 0, sumB = 0;
    cin >> a >> b;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;
    sumA = a + a1 + a2 + a3;
    sumB = b + b1 + b2 + b3;
    if (sumA > sumB)
        cout << "1" << endl;
    else if (sumA < sumB)
        cout << "2" << endl;
    else
        cout << "DRAW" << endl;
}