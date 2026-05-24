#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid(101, vector<int>(101, -1));

int main() {
    int n, zsum = 0, osum = 0, msum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'S') {
            int x, y;
            bool b;
            cin >> x >> y >> b;
            grid[x][y] = b;
        } else if (c == 'L') {
            int x, y;
            cin >> x >> y;
            if (grid[x][y] == -1) {
                msum++;
            } else if (grid[x][y] == 0) {
                zsum++;
            } else {
                osum++;
            }
        } else if (c == 'C') {
            for (int i = 0; i < 101; i++) {
                for (int j = 0; j < 101; j++) {
                    grid[i][j] = -1;
                }
            }
        }
    }

    cout << zsum << " " << osum << " " << msum;
    return 0;
}
