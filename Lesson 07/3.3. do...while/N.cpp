#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x = 100, sum = 0, sumx = 0, n = -1;
    do
    {
        cin >> x;
        sum += x;
        sumx += x * x;
        n++;
    } while (x != 0);
    cout << fixed << sqrt((sumx - 1.0 * sum * sum / n) / (n - 1));
}