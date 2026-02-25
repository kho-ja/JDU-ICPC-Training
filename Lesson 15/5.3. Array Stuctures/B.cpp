#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Person {
    string fio;
    string address;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map<string, Person> book;

    for (int i = 0; i < N; i++) {
        string phone;
        string fio;
        string address;

        cin >> phone;
        cin.ignore();
        getline(cin, fio);
        getline(cin, address);

        book[phone] = {fio, address};
    }

    for (int i = 0; i < M; i++) {
        string phone;
        cin >> phone;

        Person p = book[phone];
        cout << p.fio << " (" << p.address << ")\n";
    }

    return 0;
}