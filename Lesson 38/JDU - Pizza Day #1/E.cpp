#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (auto &a : A)
    cin >> a;
  for (auto &b : B)
    cin >> b;

  bool isOdd = (B[0] == 0) || A[0] % 2;
  for (int i = 1; i < N; i++) {
    bool isIOdd = (B[i] == 0) || (A[i] % 2);
    isOdd = isOdd ^ isIOdd;
  }
  cout << (isOdd ? "Odd" : "Even") << endl;

  return 0;
}
