#include <deque>
#include <iostream>
using namespace std;

int main () {
    deque<int> dq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        switch (x) {
            case 1:
                cin >> x;
                dq.push_front(x);
                break;
            case 2:
                cin >> x;
                dq.push_back(x);
                break;
            case 3:
                cout << dq.front() << " ";
                dq.pop_front();
                break;
            case 4:
                cout << dq.back() << " ";
                dq.pop_back();
                break;
        }
    }
    return 0;
}
