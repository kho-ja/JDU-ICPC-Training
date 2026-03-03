#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n - 1; i >= 0; i--) {
        int mxid = 0;

        for (int j = 1; j <= i; j++)
            if (a[j] > a[mxid])
                mxid = j;

        cout << mxid << " ";
        swap(a[mxid], a[i]);
    }

    delete[] a;
    return 0;
}