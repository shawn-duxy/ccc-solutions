#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> nodes(m + 1);
  vector<vector<pair<int, int>>> graph(m + 1);
  vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> edges(n);

  nodes[0] = {1, 1, 0};
  edges[0].push({0, 0});
  for (int i = 0; i < m; i++) {
    int s, e, c;
    cin >> s >> e >> c;
    nodes[i + 1] = {s, e, c};
    edges[s - 1].push({c, i + 1});
    edges[e - 1].push({c, i + 1});
  }

  for (auto edge : edges) {
    auto start = edge.top();
    edge.pop();
    while (!edge.empty()) {
      auto end = edge.top();
      edge.pop();
      graph[start.second].emplace_back(end.second, abs(start.first - end.first));
      graph[end.second].emplace_back(start.second, abs(end.first - start.first));
      start = end;
    }
  }

  vector<long> dist(m + 1, LONG_MAX);
  dist[0] = 0;
  priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> notVisited{};
  notVisited.push({0, 0});

  while (!notVisited.empty()) {
    auto next = notVisited.top();
    notVisited.pop();
    for (auto edge : graph[next.second]) {
      long p = dist[next.second] + edge.second;
      if (p < dist[edge.first]) {
        dist[edge.first] = p;
        notVisited.push({p, edge.first});
      }
    }
  }

  long minDist = LONG_MAX;
  for (int i = 0; i <= m; i++) {
    if (nodes[i][0] == n || nodes[i][1] == n) {
      minDist = min(minDist, dist[i]);
    }
  }
  cout << minDist << endl;
}