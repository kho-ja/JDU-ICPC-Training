#include <iostream>
using namespace std;

int main()
{
    string keyboard = "qwertyuiopasdfghjklzxcvbnmq";
    char c;
    cin >> c;
    cout << keyboard[keyboard.find(c) + 1];
}