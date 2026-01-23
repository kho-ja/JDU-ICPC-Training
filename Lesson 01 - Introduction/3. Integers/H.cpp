#include <iostream>
using namespace std;

int main()
{
    int V, T;
    cin >> V >> T;
    cout << (V * T % 109 + 109) % 109 + 1 << endl;
}