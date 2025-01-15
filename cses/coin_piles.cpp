#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  int t;
  std::cin >> t;
  while (t-- > 0) {
    int a, b;
    std::cin >> a >> b;
    int s1 = 2 * b - a;
    int s2 = 2 * a - b;
    if (s1 >= 0 && s1 % 3 == 0 && s2 >= 0 && s2 % 3 == 0) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}

