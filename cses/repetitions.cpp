#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main () {
  string s;
  cin >> s;
  int max_size = 1;
  int temp = 1;
  for (size_t i = 1; i < s.length(); i++) {
    if (s[i] == s[i-1]) {
      temp++;
    } else {
      temp = 1;
    }
    max_size = max(temp, max_size);
  }
  cout << max_size;
  return 0;
}
