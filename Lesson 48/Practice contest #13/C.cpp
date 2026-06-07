#include <iostream>
using namespace std;

int main() {
    string name, surname;
    cin >> name >> surname;
    if (name.back() == 'v') swap(name, surname);
    cout << name << " " << surname;
    return 0;
}
