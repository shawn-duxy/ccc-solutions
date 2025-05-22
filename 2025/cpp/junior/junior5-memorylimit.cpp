#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c, m;
  cin >> r >> c >> m;

  auto grid = vector<vector<int>>(r);
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

  auto path = vector<vector<int>>(r);
  for (int i = r - 1; i >= 0; i--) {
    for (int j = 0; j < c; j++) {
      if (i == r - 1) {
        path[i].push_back(grid[i][j]);
      } else {
        int smallest = path[i + 1][j];
        if (j > 0) {
          smallest = min(smallest, path[i + 1][j - 1]);
        }
        if (j < c - 1) {
          smallest = min(smallest, path[i + 1][j + 1]);
        }
        path[i].push_back(smallest + grid[i][j]);
      }
    }
  }

  cout << *min_element(path[0].begin(), path[0].end());
}
