#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000 + 3;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> tasks{};
  vector<pair<long, long>> tree((1 << 21) + 1, pair<long, long>(0L, 0L));
  for (int i = 0; i < n; i++) {
    long ans = tree[1].first;
    string op;
    cin >> op;

    int pos = 0;
    if (op == "A") {
      int s, t;
      cin >> s >> t;
      s = static_cast<int>((s + ans - 1) % MOD);
      t = static_cast<int>((t + ans) % MOD);
      pos = (1 << 20) + s + 1;
      tasks.emplace_back(s, t);
      auto node = tree[pos];
      tree[pos] = pair<long, long>(s + node.second + t, node.second + t);
    } else {
      int idx;
      cin >> idx;
      idx = static_cast<int>((idx + ans) % MOD);
      auto task = tasks[idx - 1];
      pos = (1 << 20) + task.first + 1;
      auto node = tree[pos];
      if (task.second == node.second) {
        tree[pos] = pair<long, long>(0, 0);
      } else {
        tree[pos] = pair<long, long>(node.first - task.second, node.second - task.second);
      }
    }

    pos = pos >> 1;
    while (true) {
      auto left = tree[pos << 1];
      auto right = tree[(pos << 1) + 1];
      tree[pos].first = max(left.first + right.second, right.first);
      tree[pos].second = left.second + right.second;

      if (pos == 1) {
        break;
      }
      pos = pos >> 1;
    }

    cout << tree[1].first << endl;
  }
}