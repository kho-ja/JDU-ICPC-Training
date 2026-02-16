#include <iostream>
using namespace std;

int main()
{
    int n, k, product = 1, sum = 0;
    cin >> n >> k;
    do
    {
        int num = n % k;
        product *= num;
        sum += num;
        n /= k;
    } while (n);

    cout << product - sum;
}