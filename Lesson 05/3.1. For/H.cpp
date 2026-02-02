#include <iostream>
using namespace std;

int main()
{
    long long n, sum = 0;
    cin >> n;
    if (n >= 1) {
        sum = n * (n + 1) / 2;
    } else {
        sum = 1 - (n * (n - 1) / 2);
    }

    cout << sum;
}