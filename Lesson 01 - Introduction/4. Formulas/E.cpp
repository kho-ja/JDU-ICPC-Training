#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    k = 45 * k + k / 2 * 5 + (k - 1) / 2 * 15;
    cout << 9 + k / 60 << " " << k % 60;
}