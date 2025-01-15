#include <iostream>
int main (int argc, char *argv[]) {
  int m;
  std::cin >> m;
  for (long n=1; n<=m; n++) {
    std::cout << ((n*n)*(n*n-1))/2 - 4*(n-2)*(n-1) << "\n";
  }
  return 0;
}
