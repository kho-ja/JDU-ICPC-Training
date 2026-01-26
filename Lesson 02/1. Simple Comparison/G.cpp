// #include <iostream>
// using namespace std;

// int main()
// {
//     int a;
//     cin >> a;
//     if (a == 1) cout << 0;
//     else if (a % 2 == 0) cout << a / 2;
//     else cout << a;
// }

#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    cout << (a == 1 ? 0 : (a / (2 - a % 2)));
}