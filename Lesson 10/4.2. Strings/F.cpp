#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        int j;
        getline(cin, s);
        j = s.find_last_of(" ");
        while (j != string::npos)
        {
            cout << s.substr(j + 1) << " ";
            s.erase(j);
            j = s.find_last_of(" ");
        }
        cout << s << endl;
    }
}