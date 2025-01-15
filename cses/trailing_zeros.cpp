#include <algorithm>
#include <iostream>
int main (int argc, char *argv[]) {
  int n;
  std::cin >> n;
  int count2s = 0;
  int temp = n;
  while (temp>=2) {
    count2s += temp/2;
    temp = temp/2;
  }
  temp = n;
  int count5s = 0;
  while (temp>=5) {
    count5s += temp/5;
    temp = temp/5;
  }
  std::cout << std::min(count2s, count5s);
  return 0;
}
