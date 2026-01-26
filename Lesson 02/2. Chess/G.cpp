#include <iostream>
using namespace std;

int main ()
{
    char X, Y;
    cin >> X >> Y;
    cout << ((X + Y) % 2 ? "WHITE" : "BLACK");
}