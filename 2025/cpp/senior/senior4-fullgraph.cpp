#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  auto nodes = vector<vector<int>>(m + 1);
  auto graph = vector<vector<pair<int, int>>>(m + 1);
  auto edges = vector<vector<int>>(n);

  nodes[0] = {1, 1, 0};
  edges[0].push_back(0);
  for (int i = 0; i < m; i++) {
    int s, e, c;
    cin >> s >> e >> c;
    nodes[i + 1] = {s, e, c};
    edges[s - 1].push_back(i + 1);
    edges[e - 1].push_back(i + 1);
  }

  for (int i = 0; i <= m; i++) {
    auto node = nodes[i];
    for(int j : edges[node[0] - 1]) {
      if (j != i) {
        graph[j].emplace_back(i, abs(nodes[j][2] - node[2]));
      }
    }
    if (node[0] != node[1]) {
      for(int j : edges[node[1] - 1]) {
        if (j != i) {
          graph[j].emplace_back(i, abs(nodes[j][2] - node[2]));
        }
      }
    }
  }

  auto dist = vector<long>(m + 1, LONG_MAX);
  dist[0] = 0;
  auto notVisited = priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>>();
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