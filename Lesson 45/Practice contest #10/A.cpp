#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int i = 2;
    while (i--) {
        if (A >= C && B >= D) {
            cout << "KOK";
            return 0;
        } else if (C >= A && D >= B) {
            cout << "QIZIL";
            return 0;
        }
        swap(A, B);
    }
    cout << "MUMKIN EMAS";
    return 0;
}
