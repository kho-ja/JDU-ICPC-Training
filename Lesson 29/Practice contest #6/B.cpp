#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct vowelCounter {
    int a = 0, e = 0, i = 0, o = 0, u = 0, other = 0;
    void increment(char c) {
        switch (c) {
        case 'a':
            a++;
            break;
        case 'e':
            e++;
            break;
        case 'i':
            i++;
            break;
        case 'o':
            o++;
            break;
        case 'u':
            u++;
            break;

        default:
            other++;
            break;
        }
    }
    void showStatsHighestFirst() {
        vector<pair<int, char>> v = {
            {a, 'a'},
            {e, 'e'},
            {i, 'i'},
            {o, 'o'},
            {u, 'u'}
        };
        sort(v.begin(), v.end(), [](const pair<int, char>& p1, const pair<int, char>& p2) {
            return p1.first > p2.first;
            });
        for (const auto& p : v) {
            cout << p.second << ":" << p.first << " ";
        }
    }
};

int main() {
    char c;
    vowelCounter vc;
    while (cin >> c) {
        c = tolower(c);
        vc.increment(c);
    }
    vc.showStatsHighestFirst();
    return 0;
}