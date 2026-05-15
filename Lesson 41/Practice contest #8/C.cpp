#include <iostream>
using namespace std;

int arr[1001];

int main() {
    int j = 1;
    bool f = true;
    for (int i = 0; i < 1001; i++) {
        arr[i] = j;

        if (j == 4) f = false;
        if (j == 1) f = true;

        if (f) j++;
        else j--;
    }
    int n;
    cin >> n;
    cout << arr[n] << endl;
    return 0;
}
