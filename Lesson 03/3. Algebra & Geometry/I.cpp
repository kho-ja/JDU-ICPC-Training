#include <iostream>
using namespace std;

int main()
{
    int l1, w1, h1, l2, w2, h2, lc, wc, hc;
    cin >> l1 >> w1 >> h1 >> l2 >> w2 >> h2 >> lc >> wc >> hc;

    if (h1 + h2 <= hc)
        cout << (max(min(l1, w1), min(l2, w2)) <= min(lc, wc) &&
                         max(max(l1, w1), max(l2, w2)) <= max(lc, wc)
                     ? "YES"
                     : "NO");
    else
        cout << (max(h1, h2) <= hc && ((w1 + w2 <= wc && max(l1, l2) <= lc) ||
                                       (w1 + l2 <= wc && max(l1, w2) <= lc) ||
                                       (l1 + w2 <= wc && max(w1, l2) <= lc) ||
                                       (l1 + l2 <= wc && max(w1, w2) <= lc) ||
                                       (l1 + l2 <= lc && max(w1, w2) <= wc) ||
                                       (l1 + w2 <= lc && max(w1, l2) <= wc) ||
                                       (w1 + l2 <= lc && max(l1, w2) <= wc) ||
                                       (w1 + w2 <= lc && max(l1, l2) <= wc))
                     ? "YES"
                     : "NO");
}