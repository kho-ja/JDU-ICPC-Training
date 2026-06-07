#include <iostream>
using namespace std;

int main()
{
    int x, y;
    int xL = -1e9, xR = 1e9, yL = xL, yR = xR, midX, midY;
    do {
        midX = (xL + xR) / 2;
        midY = (yL + yR) / 2;
        cout << midX << " " << midY << endl;
        cin >> x >> y;

        if (x == 0) {
            xL = xR = midX;
        } else if (x > 0) {
            xL = midX + x + 1;
            xR+=x;

        } else if (x < 0) {
            xR = midX + x - 1;
            xL+=x;
        }

        if (y == 0) {
            yL = yR = midY;
        } else if (y > 0) {
            yL = midY + y + 1;
            yR+=y;

        } else if (y < 0) {
            yR = midY + y - 1;
            yL+=y;
        }
    } while(x != 0 || y != 0);
}