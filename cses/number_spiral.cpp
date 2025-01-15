#include <algorithm>
#include <iostream>
using namespace std;
int main (int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t-- > 0) {
    long x, y;
    cin >> x >> y;
    long max = std::max(x, y);
    long long ans;
    cout << (max-1)*(max-1) + max + x + y - 2*(max%2==0?y:x) << "\n";
  }
  return 0;
}
