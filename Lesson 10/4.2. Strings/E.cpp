#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.find(">>-->"), count = 0;
    while (n != string::npos)
    {
        count++;
        n = s.find(">>-->", n + 1);
    }
    n = s.find("<--<<");
    while (n != string::npos)
    {
        count++;
        n = s.find("<--<<", n + 1);
    }
    cout << count;
}