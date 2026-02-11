#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    cout << (isupper(c) ? (char)tolower(c) : (char)toupper(c)) << "\n";
}