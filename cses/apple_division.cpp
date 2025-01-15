#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
long long minRes = 1 << 30;

void minDivision(vector<int> arr, int i, long long sum, long long total, int size);

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr.push_back(a);
  }
  long long sum = 0;
  for (int a : arr) {
    sum += a;
  }
  // cout << "total = " << sum << endl;
  minDivision(arr, 0, 0, sum, n);

  cout << minRes;
  return 0;
}

void minDivision(vector<int> arr, int i, long long sum, long long total, int size) {
  // this_thread::sleep_for(chrono::seconds(1));
  // cout << "index = " << i << ", sum = " << sum << endl;
  if (i == size) {
    minRes = std::min(abs(total - 2 * sum), minRes);
    return;
  }
  minDivision(arr, i + 1, sum, total, size);
  minDivision(arr, i + 1, sum + arr[i], total, size);
}
