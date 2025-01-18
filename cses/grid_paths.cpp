#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
static int moves[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool visited[9][9];

int solve(int sArr[48], int indx, int row, int col) {
  pair<int, int> key = {row, col};
  if (visited[row][col + 1] && visited[row][col - 1] &&
      !visited[row + 1][col] && !visited[row - 1][col]) {
    return 0;
  }
  if (visited[row + 1][col + 1] && visited[row - 1][col] &&
      !visited[row][col + 1] && !visited[row][col - 1]) {
    return 0;
  }

  if (row == 7 && col == 1) {
    return indx == 48 ? 1 : 0;
  }
  if (indx == 48) {
    return 0;
  }

  visited[row][col] = true;
  int res = 0;
  if (sArr[indx] < 4) {
    int nxtRow = row + moves[sArr[indx]][0];
    int nxtCol = col + moves[sArr[indx]][1];
    if (!visited[nxtRow][nxtCol]) {
      res += solve(sArr, indx + 1, nxtRow, nxtCol);
    }
  } else {
    for (auto move : moves) {
      int nxtRow = row + move[0];
      int nxtCol = col + move[1];
      if (!visited[nxtRow][nxtCol]) {
        res += solve(sArr, indx + 1, nxtRow, nxtCol);
      }
    }
  }
  visited[row][col] = false;
  // cout << "index = " << indx << ", row = " << row << ", col = " << col
  // << ", res = " << res << endl;
  return res;
}

int main(int argc, char *argv[]) {
  string s;
  getline(cin, s);
  for (int i = 0; i < 9; i++) {
    visited[0][i] = true;
    visited[8][i] = true;
    visited[i][0] = true;
    visited[i][8] = true;
  }
  int sArr[48];
  for (int i = 0; i < 48; i++) {
    if (s[i] == '?')
      sArr[i] = 4;
    else if (s[i] == 'R')
      sArr[i] = 0;
    else if (s[i] == 'L')
      sArr[i] = 1;
    else if (s[i] == 'U')
      sArr[i] = 2;
    else if (s[i] == 'D')
      sArr[i] = 3;
  }
  for (int i = 1; i < 8; i++) {
    for (int j = 1; j < 8; j++) {
      visited[i][j] = false;
    }
  }
  cout << solve(sArr, 0, 1, 1);
  return 0;
}
