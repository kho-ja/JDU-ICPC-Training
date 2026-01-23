#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << (a % b + abs(b)) % b << endl;
}