#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c, m;
  cin >> r >> c >> m;

  vector<int> row{};
  int tile = (r - 1) * c % m + 1;
  for (int i = 0; i < c; i++) {
    row.push_back(tile);
    tile = tile % m + 1;
  }

  for (int i = r - 2; i >= 0; i--) {
    vector<int> nextRow{};
    for (int j = 0; j < c; j++) {
      int smallest = row[j];
      if (j > 0) {
        smallest = min(smallest, row[j - 1]);
      }
      if (j < c - 1) {
        smallest = min(smallest, row[j + 1]);
      }
      nextRow.push_back(smallest + (i * c + j) % m + 1);
    }
    row = nextRow;
  }

  cout << *min_element(row.begin(), row.end());
}
