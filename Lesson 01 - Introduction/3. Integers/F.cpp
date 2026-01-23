#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << ((a % b == 0) || (b % a == 0) ? 1 : 666);
}


//* the bese solution
// #include <iostream>
// using namespace std;

// int main()
// {
//     int a, b;
//     cin >> a >> b;
// 	cout << (a%b)*(b%a)+1;
// }