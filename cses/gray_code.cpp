#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {

  int n;
  std::cin >> n;
  
  vector<string> ans;
  ans.push_back("");
  for (int i=0; i<n; i++) {
    vector<string> temp;
    for (int j=0; j<ans.size(); j++) {
      temp.push_back("0"+ans[j]);
    }
    for (int j=ans.size()-1; j>=0; j--) {
      temp.push_back("1"+ans[j]);
    }
    ans = temp;
  }

  for (string s : ans) {
    cout << s << endl;
  }
  return 0;
}
