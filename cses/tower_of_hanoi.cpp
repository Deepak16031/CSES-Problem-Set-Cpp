#include <iostream>
using namespace std;
void solve(int n, int src, int tar, int extra) {
  if (n==0) {
    return;
  }
  solve(n-1, src, extra, tar);
  cout << src << " " << tar << endl;
  solve(n-1, extra, tar, src);
}
int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  int ops = 1 << n;
  cout << ops - 1 << endl;
  solve(n, 1, 3, 2);
  return 0;
}
