#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  vector<pair<int, pair<int, int>>> pens{};
  vector<set<pair<int, int>>> colors(m);
  set<pair<int, int>> first{};
  set<pair<int, int>> second{};

  for (int i = 0; i < n; i++) {
    int c, p;
    cin >> c >> p;
    auto pen = pair<int, int>(p, i);
    pens.emplace_back(c, pen);
    colors[c - 1].insert(pen);
  }

  long sumFirst = 0;
  for (auto colorPens : colors) {
    auto pen = *prev(colorPens.end());
    first.insert(pen);
    sumFirst += pen.first;
    if (colorPens.size() > 1) {
      second.insert(*prev(prev(colorPens.end())));
    }
  }

  int worstFirst = first.begin()->first;
  int bestSecond = -1;
  if (second.size() > 0) {
    bestSecond = prev(second.end())->first;
  }
  if (worstFirst < bestSecond) {
    cout << sumFirst - worstFirst + bestSecond << endl;
  } else {
    cout << sumFirst << endl;
  }

  for (int i = 0; i < q; i++) {
    string t;
    int id, v;
    cin >> t >> id >> v;

    auto oldPen = pens[id - 1].second;
    int oldColor = pens[id - 1].first;
    pair<int, int> newPen;
    int newColor;
    if (t == "1") {
      newColor = v;
      newPen = oldPen;
    } else {
      newColor = oldColor;
      newPen = {v, oldPen.second};
    }
    first.erase(*prev(colors[oldColor - 1].end()));
    if (colors[oldColor - 1].size() > 1) {
      second.erase(*prev(prev(colors[oldColor - 1].end())));
    }
    first.erase(*prev(colors[newColor - 1].end()));
    if (colors[newColor - 1].size() > 1) {
      second.erase(*prev(prev(colors[newColor - 1].end())));
    }

    pens[id - 1] = {newColor, newPen};
    colors[oldColor - 1].erase(oldPen);
    colors[newColor - 1].insert(newPen);
    first.insert(*prev(colors[oldColor - 1].end()));
    if (colors[oldColor - 1].size() > 1) {
      second.insert(*prev(prev(colors[oldColor - 1].end())));
    }
    first.insert(*prev(colors[newColor - 1].end()));
    if (colors[newColor - 1].size() > 1) {
      second.insert(*prev(prev(colors[newColor - 1].end())));
    }

    sumFirst = accumulate(first.begin(), first.end(), 0L, [](long acc, const pair<int, int>& pen){ return acc + pen.first; });
    worstFirst = first.begin()->first;
    bestSecond = -1;
    if (second.size() > 0) {
      bestSecond = prev(second.end())->first;
    }
    if (worstFirst < bestSecond) {
      cout << sumFirst - worstFirst + bestSecond << endl;
    } else {
      cout << sumFirst << endl;
    }
  }
}
