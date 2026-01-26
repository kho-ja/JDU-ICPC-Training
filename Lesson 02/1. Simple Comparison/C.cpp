#include <iostream>
using namespace std;

int main()
{
    int num, SUM, sum;
    cin >> num;
    SUM = num % 10 + (num / 10) % 10 + (num / 100) % 10;
    num = num / 1000;
    sum = num % 10 + (num / 10) % 10 + (num / 100) % 10;
    if (SUM == sum)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}