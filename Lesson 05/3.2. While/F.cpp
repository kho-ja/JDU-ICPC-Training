#include <iostream>
using namespace std;

int main()
{
    int n, a = 0, b = 1, cnt = 0;
    cin >> n;
    while (n > a) {
        b = a + b;
        a = b - a;
        cnt ++;
    }
    if (n == a) {
        cout << "1\n" << cnt;
    } else
        cout << "0";
}