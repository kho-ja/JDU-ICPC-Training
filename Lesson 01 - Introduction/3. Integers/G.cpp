#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    cout << K / N << " " << K % N << " " << (N - K % N) % N << endl;
}