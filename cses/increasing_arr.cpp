#include <algorithm>
#include <iostream>
using namespace std;
int main (int argc, char *argv[]) {
  int n;
  cin >> n;
  long long moves = 0;
  int first;
  cin >> first;
  for (int i=1; i<n; i++) {
    int second;
    cin >> second;
    // cout << "first:" << first << " second:" << second;
    moves += max(0, first-second);
    first = max(first, second);
  }
  cout << moves;
  return 0;
}
