#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int A = a;
    while (b) swap(a %= b, b);
    cout << A / a;
}