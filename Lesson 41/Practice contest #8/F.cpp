#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> score(4);
    vector<string> note(4);
    vector<string> ans(4);
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        note[i] = s;
    }
    for (int i = 0, x; i < 4; i++) {
        cin >> x;
        score[i] = x;
    }
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        ans[i] = s;
    }

    bool correct = true;
    for (int i = 0; i < 4; i++)
        if (ans[i] != "?")
            for (int j = i + 1; j < 4; j++)
                if (ans[i] == ans[j]) correct = false;

    vector<int> res;
    if (correct) {
        cout << "HA\n";
        for (int i = 0; i < 4; i++)
            if (ans[i] != "?"){
                int id = find(note.begin(), note.end(), ans[i]) - note.begin();
                score[id] = 1;
            }
        int answer = 1;
        for (int i = 0; i < 4; i++)
            answer *= score[i];
        cout << answer;
    } else {
        cout << "YO'Q\n0";
    }

    return 0;
}
