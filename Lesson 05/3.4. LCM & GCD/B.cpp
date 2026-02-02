#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int P = a * b;
    while (b) swap(a %= b, b);
    cout << P / a;
}