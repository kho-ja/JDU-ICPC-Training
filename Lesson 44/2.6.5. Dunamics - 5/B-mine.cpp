#include <iostream>
using namespace std;

struct dir {
    string N, S, W, E, U, D;
    void read() {
        cin >> N >> S >> W >> E >> U >> D;
    }
    int count (string run, int command) {
        int result = 0;
        for (int i = 0; i < run.size(); i++) {
            if 
        }
        return result;
    }
};

int main() {
    dir d;
    d.read();
    string run;
    int command;
    cin >> run >> command;
    cout << d.count(run, command);
    return 0;
}
