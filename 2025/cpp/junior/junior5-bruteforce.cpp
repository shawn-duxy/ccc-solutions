#include <bits/stdc++.h>
using namespace std;

int findMin(vector<vector<int>> &grid, int r, int c) {
  if (r == grid.size() - 1) {
    return grid[r][c];
  }
  int res = findMin(grid, r + 1, c);
  if (c > 0) {
    res = min(res, findMin(grid, r + 1, c - 1));
  }
  if (c < grid[r].size() - 1) {
    res = min(res, findMin(grid, r + 1, c + 1));
  }
  return res + grid[r][c];
}

int main() {
  int r, c, m;
  cin >> r >> c >> m;

  vector<vector<int>> grid(r);
  int tile = 1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      grid[i].push_back(tile);
      tile = (tile + 1) % m;
      if (tile == 0) {
        tile = m;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < c; i++) {
    int n = findMin(grid, 0, i);
    if (ans == 0) {
      ans = n;
    } else {
      ans = min(ans, n);
    }
  }

  cout << ans;
}
