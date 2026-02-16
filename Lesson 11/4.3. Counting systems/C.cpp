#include <iostream>
using namespace std;

int main()
{
    string n, m;
    int N = 0, M = 0;
    cin >> n >> m;

    for (char c : n)
        N = N * 3 + (c - '0');
    for (char c : m)
        M = M * 3 + (c - '0');

    cout << 0LL + N + M;
}