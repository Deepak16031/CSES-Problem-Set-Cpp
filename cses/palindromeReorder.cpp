#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
// void latency(clock_t start);
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  clock_t start = clock();

  string s;
  cin >> s;
  // latency(start);
  // cout << s.length() << endl;
  unordered_map<char, int> freqMap;
  for (int i = 0; i < s.length(); i++) {
    freqMap[s[i]]++;
  }
  // latency(start);
  list<char> ans;
  bool flag = false;
  for (auto &pair : freqMap) {
    if (pair.second % 2 != 0) {
      if (flag) {
        cout << "NO SOLUTION";
        return 0;
      }
      flag = true;
      auto it = ans.begin();
      advance(it, ans.size()/2);
      ans.insert(it, pair.first);
      pair.second -= 1;
    }
    while (pair.second > 0) {
      pair.second -= 2;
      ans.push_back(pair.first);
      ans.push_front(pair.first);
    }
  }
   // latency(start);
  for (char c : ans) {
    cout << c;
  }
  return 0;
}

//void latency(clock_t start) {
// clock_t end = clock();
//  double time_taken = double(end-start) / CLOCKS_PER_SEC;
//  cout << "Exec time :" << time_taken << endl;
//}
