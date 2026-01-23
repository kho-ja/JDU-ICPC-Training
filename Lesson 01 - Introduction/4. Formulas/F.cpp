#include <iostream>
using namespace std;

int main()
{
    int h, a, b;
    cin >> h >> a >> b;
    cout << max((h - b - 1) / (a - b) + 1, 1);
}