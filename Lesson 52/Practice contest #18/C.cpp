#include <iostream>
#include <string>
using namespace std;

int n;

int get(int num = 1) {
    if (num <= n) return 1 + get(num * 10) + get(num * 10 + 1);
    else return 0;
}

int main() {
    cin >> n;
    cout << get();
    return 0;
}
