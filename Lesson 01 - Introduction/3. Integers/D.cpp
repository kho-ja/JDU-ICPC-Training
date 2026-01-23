#include <iostream>

int main()
{
    int a;
    std::cin >> a;
    std::cout << a % 10 + a / 10 % 10 + a / 100 % 10 << std::endl;
    return 0;
}