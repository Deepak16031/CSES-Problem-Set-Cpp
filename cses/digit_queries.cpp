#include <charconv>
#include <cstddef>
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

int arr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isValid(map<pair<int, int>, int> visited, int indx, int row, int col) {
  return indx >= 0 && indx <= 47 && row >= 0 && row <= 6 && col >= 0 &&
         col <= 6 && visited.count(pair(row, col));
}

bool solve(map<pair<int, int>, int> visited, string s, int indx, int row,
           int col) {
  if (indx == 48) {
    return row == 6 && col == 0;
  }
  if (!isValid(visited, indx, row, col)) {
    return false;
  }
  for (int move[2] : range-expression) {
  
  }
}
int main() {
  std::string s;
  cin >> s;
  map<pair<int, int>, int> visited;
  cout << solve(s, 0, 0, 0);
  return 0;
}
