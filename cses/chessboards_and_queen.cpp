#include <iostream>
#include <set>
#include <string>
using namespace std;

bool isValid(char chess[8][8], int row, int col, set<int> columns,
             set<int> positiveDiagonals, set<int> negativeDiagonals) {

  return chess[row][col] == '.' && !columns.count(col) &&
         !positiveDiagonals.count(row + col) &&
         !negativeDiagonals.count(row - col);
}
int solve(char chess[8][8], int row, set<int> columns,
          set<int> positiveDiagonals, set<int> negativeDiagonals) {

  // cout << row << endl;
  // for (int i = 0; i < 8; i++) {
    // for (int j=0; j<8; j++) {
      // cout << chess[i][j]; 
    // }
    // cout << endl;
  // }
  if (row == 8) {
    return 1;
  }
  int res = 0;
  for (int i = 0; i < 8; i++) {
    if (isValid(chess, row, i, columns, positiveDiagonals, negativeDiagonals)) {
      columns.insert(i);
      positiveDiagonals.insert(row + i);
      negativeDiagonals.insert(row - i);

      chess[row][i] = static_cast<char>('0' + row); 
      res += solve(chess, row+1, columns, positiveDiagonals, negativeDiagonals);

      chess[row][i] = '.';
      columns.erase(i);
      positiveDiagonals.erase(row + i);
      negativeDiagonals.erase(row - i);
    }
  }
  return res;
}
int main() {

  int n = 8;
  char chess[8][8];
  for (int i = 0; i < 8; i++) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < 8; j++) {
      chess[i][j] = s[j];
    }
  }
  set<int> positiveDiagonals;
  set<int> negativeDiagonals;
  set<int> columns;
  cout << solve(chess, 0, columns, positiveDiagonals, negativeDiagonals);
  return 0;
}
