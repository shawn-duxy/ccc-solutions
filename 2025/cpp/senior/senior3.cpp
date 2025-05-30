#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  vector<pair<int, pair<int, int>>> pens{};
  set<pair<int, int>> best{};
  set<pair<int, int>> other{};
  vector<set<pair<int, int>>> colors(m);

  for (int i = 0; i < n; i++) {
    int c, p;
    cin >> c >> p;
    auto pen = pair<int, int>(p, i);
    pens.emplace_back(c, pen);
    colors[c - 1].insert(pen);
    other.insert(pen);
  }

  long sumFirst = 0;
  for (int i = 0; i < m; i++) {
    auto pen = *prev(colors[i].end());
    best.insert(pen);
    sumFirst += pen.first;
    other.erase(pen);
  }

  auto worstFirst = *best.begin();
  if (!other.empty()) {
    auto bestOther = *prev(other.end());
    if (worstFirst.first < bestOther.first) {
      cout << sumFirst - worstFirst.first + bestOther.first << endl;
    } else {
      cout << sumFirst << endl;
    }
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

    pens[id - 1] = {newColor, newPen};
    if (t == "1") {
      bool firstRemoved = best.erase(oldPen);
      colors[oldColor - 1].erase(oldPen);
      if (firstRemoved) {
        sumFirst -= oldPen.first;
        auto newBest = *prev(colors[oldColor - 1].end());
        best.insert(newBest);
        sumFirst += newBest.first;
        other.erase(newBest);
      } else {
        other.erase(oldPen);
      }

      auto currentBest = *prev(colors[newColor - 1].end());
      colors[newColor - 1].insert(newPen);
      auto newBest = *prev(colors[newColor - 1].end());
      if (newBest.second != currentBest.second) {
        best.erase(currentBest);
        sumFirst -= currentBest.first;
        other.insert(currentBest);
        best.insert(newBest);
        sumFirst += newBest.first;
      }
      if (newBest.second != newPen.second) {
        other.insert(newPen);
      }
    } else {
      auto currentBest = *prev(colors[oldColor - 1].end());
      colors[oldColor - 1].erase(oldPen);
      colors[newColor - 1].insert(newPen);
      auto newBest = *prev(colors[newColor - 1].end());

      best.erase(currentBest);
      sumFirst -= currentBest.first;
      other.insert(currentBest);
      other.erase(oldPen);
      other.insert(newPen);
      other.erase(newBest);
      best.insert(newBest);
      sumFirst += newBest.first;
    }

    worstFirst = *best.begin();
    if (!other.empty()) {
      auto bestOther = *prev(other.end());
      if (worstFirst.first < bestOther.first) {
        cout << sumFirst - worstFirst.first + bestOther.first << endl;
      } else {
        cout << sumFirst << endl;
      }
    } else {
      cout << sumFirst << endl;
    }
  }
}
