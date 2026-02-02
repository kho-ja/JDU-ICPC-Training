#include <iostream>
using namespace std;

int main()
{
    int x, p, y, result = 0;
    cin >> x >> p >> y;
    x *= 100;
    y *= 100;

    while (x < y) {
        x += x * p / 100;
        result ++;
    }
    cout << result;
}