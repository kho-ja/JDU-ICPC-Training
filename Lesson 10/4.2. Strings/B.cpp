#include <iostream>
using namespace std;

int main()
{
    string s = "GCVGCVG";
    int i;
    cin >> i;
    cout << s.substr(i % 3 * 2, 3);
}