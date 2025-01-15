#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
void solve(long n);

int main(int argc, char *argv[]) {
  long n;

  std::cin >> n;
  solve(n);
  return 0;
}

void solve(long n) {
  int sum = (n * (n + 1)) / 2;
  if (sum % 2 != 0 || n % 4 == 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;

  set<int> setA;
  set<int> setB;
  if (n % 4 == 0) {
    for (int i = 1; i <= n / 2; i += 2) {
      setA.insert(i);
      setA.insert(n - i + 1);
      setB.insert(i + 1);
      setB.insert(n - i);
    }
  }
  if (n % 4 == 3) {

    set<int> all;
    for (int i = 1; i <= n; i++) {
      all.insert(i);
    }
    int setASum = 0;
    int i = 1;
    while (setASum != sum / 2) {
      setA.insert(i);
      setA.insert(n - i);
      setASum += n;
      all.erase(i);
      all.erase(n - i);
      i++;
      
    }
    setB.insert(n);

    i = 1;
    while (i<n) {
      if (all.count(i)) {
        setB.insert(i);
        setB.insert(n - i);
      }
      i++;
    }
  }

  if (setA.size() > setB.size()) {
    setB.insert(n);
  } else if (setB.size() > setA.size()) {
    setA.insert(n);
  }
  auto printElement = [](int element) { cout << element << " "; };
  cout << setA.size() << endl;
  for_each(setA.begin(), setA.end(), printElement);
  cout << endl;
  cout << setB.size() << endl;
  for_each(setB.begin(), setB.end(), [](int x) { cout << x << " "; });
}
