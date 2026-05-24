#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<char>> grid(4, vector<char>(4));
    for (auto& row: grid)
        for (char& cell: row)
            cin >> cell;

    sort(grid[2].begin(), grid[2].end());
    int mx = 0;
    do {
        for (int r1 = 0; r1 < 4; r1++)
            for (int c1 = 0; c1 < 4; c1++)
                for (int r2 = r1; r2 < 4; r2++)
                    for (int c2 = c1; c2 < 4; c2++) {
                        int area = (r2 - r1 + 1) * (c2 - c1 + 1);
                        if (area < mx || area > 9)
                            continue;
                        vector<bool> seen(10, 0);
                        for (int i = r1; i <= r2; i++)
                            for (int j = c1; j <= c2; j++) {
                                if (seen[grid[i][j] - '0'])
                                    goto skip;
                                seen[grid[i][j] - '0'] = true;
                            }
                        mx = area;
                        skip:;
                    }
    } while (next_permutation(grid[2].begin(), grid[2].end()));
    cout << mx;
    return 0;
}
