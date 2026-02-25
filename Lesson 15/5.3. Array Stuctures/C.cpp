#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct student {
    string name;
    int score[20], sum = 0, M = 20;
    void read(int i) {
        M = i;
        cin.ignore();
        getline(cin, name);
        for (int i = 0; i < M; i++) {
            cin >> score[i];
            sum += score[i];
        }
    }
    void writeLine() {
        cout << name << " (" << score[0];
        for (int i = 1; i < M; i++) {
            cout << " " << score[i];
        }
        cout << ") " << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, mx1 = 0, mx2 = 0, mx3 = 0;
    cin >> N >> M;
    student* s = new student[N];

    for (int i = 0; i < N; i++) {
        s[i].read(M);
        if (s[i].sum > mx1) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = s[i].sum;
        }
        else if (s[i].sum > mx2) {
            mx3 = mx2;
            mx2 = s[i].sum;
        }
        else if (s[i].sum > mx3) {
            mx3 = s[i].sum;
        }
    }

    for (int i = 0; i < N; i++)
        if (s[i].sum >= mx3)
            s[i].writeLine();

    delete[] s;
    return 0;
}