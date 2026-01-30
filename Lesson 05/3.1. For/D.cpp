#include <iostream>
using namespace std;

int main()
{
    int n, h;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> h;
        if (h <= 437)
        {
            cout << "Crash" << " " << i + 1 << "\n";
            return 0;
        }
    }
    cout << "No crash\n";
    return 0;
}