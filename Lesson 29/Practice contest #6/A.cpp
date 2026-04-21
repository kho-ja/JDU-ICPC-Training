#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int id = s.find('<');
    while (id != string::npos) {
        if (id > 0) {
            s.erase(id - 1, 2);
        }
        else {
            s.erase(id, 1);
        }
        id = s.find('<');
    }
    cout << s;
    return 0;
}