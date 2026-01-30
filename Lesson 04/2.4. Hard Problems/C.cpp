#include <iostream>
using namespace std;

int main()
{
    int k, m, n;
    cin >> k >> m >> n;
    cout << (n <= k ? 2 : ((2 * n + k - 1) / k)) * m;
}