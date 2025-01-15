#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <utility>
using namespace std;
bool next_permutation_self(string &s);
int main() {
  string s;
  cin >> s;
  std::sort(s.begin(), s.end());
  vector<string> createdString;
  do {
    createdString.push_back(s);
  } while (next_permutation_self(s));
  cout << createdString.size() << endl;
  for (string s : createdString) {
    cout << s << endl;
  }
  return 0;
}

bool next_permutation_self(string &s) {
  int i = s.length() - 2;

  while (i >= 0 && s[i] >= s[i + 1]) {
    i--;
  }
  if (i == -1) {
    return false;
  }

  int j = s.length() - 1;

  while (j > i && s[j] <= s[i]) {
    j--;
  }
  // cout << s << " " << i << "," << j << endl;
  swap(s[i], s[j]);

  j = s.length() - 1;
  i++;
  while (i < j) {
    swap(s[i], s[j]);
    j--;
    i++;
  }
  // cout << s << " swap" << endl;
  return true;
}
