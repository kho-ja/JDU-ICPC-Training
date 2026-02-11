#include <iostream>
using namespace std;

int main()
{
    char c;
    int cnt = 0, up=0, low=0, dig=0;
    while (cin >> c)
    {
        cnt++;
        if (isupper(c)) up++;
        else if (islower(c)) low++;
        else if (isdigit(c)) dig++;
    }
    cout << (cnt >= 12 && up >= 1 && low >= 1 && dig >= 1 ? "Yes" : "No");
}