#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> a;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    cout << a.size();
    return 0;
}
