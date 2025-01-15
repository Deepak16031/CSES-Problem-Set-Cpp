#include <iostream>
long solve(int n);
const long modulo = 1000000000+7;
int main (int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::cout << solve(n);
  return 0;
}

long solve(int n) {
  if (n==1) {
    return 2;
  }
  return (solve(n/2) * solve(n-n/2))%modulo;
}
