#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> numbers(101, 0);
    for (int i = 0; i < numbers.size(); i++) numbers[i] += i;
    for (int i = 0; i < N; i++) {
        string s;
        int k;
        cin >> s >> k;
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] < 0) continue;
            if (s == "ADD") {
                numbers[i] += k;
            }
            else if (s == "MULTIPLY") {
                numbers[i] *= k;
            }
            else if (s == "DIVIDE") {
                if (k != 0) {
                    if (numbers[i] % k != 0) {
                        numbers[i] = -1;
                    }
                    else {
                        numbers[i] /= k;
                    }
                }
                else {
                    numbers[i] = -1;
                }
            }
            else if (s == "SUBTRACT") {
                numbers[i] -= k;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] >= 0) cnt++;
    }
    cout << cnt;
    return 0;
}