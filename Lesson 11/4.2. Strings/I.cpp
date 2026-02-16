#include <iostream>
using namespace std;

int main()
{
    string s1, s2, s3, mx;
    cin >> s1 >> s2 >> s3;
    mx = s1.size() > s2.size()
             ? s1
         : s1.size() < s2.size()
             ? s2
             : max(s1, s2);
    cout << (mx.size() > s3.size()
                 ? mx
             : mx.size() < s3.size()
                 ? s3
                 : max(mx, s3));
    return 0;
}