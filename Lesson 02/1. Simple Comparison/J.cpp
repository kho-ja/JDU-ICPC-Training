#include <iostream>
#include <string>
using namespace std;

int main() {
    string r, y, g;
    cin >> r >> y >> g;

    if (r == "black" && y == "black" && g == "green")
        cout << "black" << "\n" << "black" << "\n" << "GREEN";

    else if (r == "black" && y == "black" && g == "GREEN")
        cout << "black" << "\n" << "yellow" << "\n" << "black";

    else if (r == "black" && y == "yellow" && g == "black")
        cout << "red" << "\n" << "black" << "\n" << "black";

    else if (r == "red" && y == "black" && g == "black")
        cout << "red" << "\n" << "yellow" << "\n" << "black";

    else if (r == "red" && y == "yellow" && g == "black")
        cout << "black" << "\n" << "black" << "\n" << "green";

    else if (r == "black" && y == "YELLOW" && g == "black")
        cout << "black" << "\n" << "YELLOW" << "\n" << "black";

    else
        cout << "error";

    return 0;
}
