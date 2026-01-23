#include <iostream>

int main()
{
    int K, N;
    std::cin >> K >> N;
    int page = (N - 1) / K;
    std::cout << page + 1 << " " << N - K * page << std::endl;
    return 0;
}