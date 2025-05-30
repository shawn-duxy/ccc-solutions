#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000 + 3;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> tasks{};
  multiset<pair<int, int>> toDo{};

  long ans = 0;
  for (int i = 0; i < n; i++) {
    string op;
    cin >> op;
    if (op == "A") {
      int s, t;
      cin >> s >> t;
      s = (s + ans - 1) % MOD;
      t = (t + ans) % MOD;
      tasks.emplace_back(s, t);
      toDo.insert({s, t});
    } else {
      int idx;
      cin >> idx;
      idx = (idx + ans) % MOD;
      toDo.erase(toDo.find(tasks[idx - 1]));
    }

    ans = 0;
    for (auto task : toDo) {
      if (task.first > ans) {
        ans = task.first + task.second;
      } else {
        ans += task.second;
      }
    }

    cout << ans << endl;
  }
}