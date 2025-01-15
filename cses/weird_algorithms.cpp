#include <iostream>  // Required for std::cout

using namespace std;

int main() {
  long long number;
  cin >> number;
  while (number != 1) {
    cout << number << " ";
    if (number % 2 ==0) {
      number = number/2;
    } else {
      number = number * 3 + 1;
    }
  }
  cout << number;
  return 0;
}