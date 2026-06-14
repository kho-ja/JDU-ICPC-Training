#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> s = {"Sardor", "Rustam", "Dilshod", "Shoxruh", "Shaxboz"};

int main() {
    int n;
    cin >> n;
    int i = 5;
    n--;
    while (n >= i) {
        n -= i;
        i *= 2;
    }
    cout << s[(n < i ? n * 5 / i : n % 5)];
    return 0;
}
