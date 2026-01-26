#include <iostream>
using namespace std;

int main ()
{
    char X, Y, X1, Y1;
    cin >> X >> Y;
    cin >> X1 >> Y1;

    if (X1 == X || Y1 == Y || abs(X - X1) == abs(Y - Y1)) {
        cout << "Queen\n";
        if (X1 != X && Y1 != Y) cout << "Bishop\n";
        else cout << "Rook\n";
        if (max(abs(X1-X), abs(Y1-Y)) == 1) cout << "King\n";
        if (X1 == X && Y > '1' && (Y1 - Y == 1 || (Y == '2' && Y1 == '4'))) cout << "Pawn\n";
    } else if (abs(X1 - X) * abs(Y1 - Y) == 2) {
        cout << "Knight\n";
    } else {
        cout << "Nobody\n";
    }
}