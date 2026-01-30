#include <iostream>
using namespace std;

int main()
{
    int k, m, n;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> n >> m;
        cout << 19 * m + (n + 239) * (n + 366) / 2 << "\n";
    }
}