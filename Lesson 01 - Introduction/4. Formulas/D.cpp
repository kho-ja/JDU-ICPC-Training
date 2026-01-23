#include <iostream>
using namespace std;

int main()
{
    int h, m, s;
    int h1, m1, s1;
    cin >> h >> m >> s >> h1 >> m1 >> s1;
    cout << 3600 * h1 + 60 * m1 + s1 - (3600 * h + 60 * m + s);
}
