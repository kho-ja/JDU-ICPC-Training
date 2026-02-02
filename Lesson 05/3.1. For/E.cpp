#include <iostream>
using namespace std;

int main()
{
    int n, S, V, res = -1, age = -1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int S, V;
        cin >> V >> S;
        if (S == 1 && age < V) {
            age = V;
            res = i;
        }
    }
    cout << res << '\n';
}