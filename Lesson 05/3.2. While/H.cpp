#include <iostream>
using namespace std;

int main()
{
    double x, y, eps = 1e-9;
    int result = 1;
    cin >> x >> y;

    while (x + eps < y)
    {
        x += x * 0.15;
        result++;
    }
    cout << result;
}