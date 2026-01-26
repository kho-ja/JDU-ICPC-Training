#include <iostream>
using namespace std;

int main()
{
    int num, N, n;
    cin >> num;
    cout << (((num % 10 * 10 + num / 10 % 10) == (num / 100)) ? "YES" : "NO");
}