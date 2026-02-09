#include <iostream>
using namespace std;

int main()
{
    int x, y;
    int xL = -1e6, xR = 1e6, yL = xL, yR = xR, midX, midY;
    do {
        midX = (xL + xR) / 2;
        midY = (yL + yR) / 2;
        cout << midX << " " << midY << endl;
        cin >> x >> y;

        if (x == 0) {
            xL = xR = midX;
        } else if (x == 1) {
            xL = midX + 2;
            xR++;

        } else if (x == -1) {
            xR = midX - 2;
            xL--;
        }

        if (y == 0) {
            yL = yR = midY;
        } else if (y == 1) {
            yL = midY + 2;
            yR++;

        } else if (y == -1) {
            yR = midY - 2;
            yL--;
        }
    } while(x != 0 || y != 0);
}