#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> EDGE;

vector<int> depth{};
vector<int> parent{};
vector<EDGE> zero_roads{};
vector<EDGE> non_zero_roads{};
vector<vector<pair<int, int>>> matrix{};

int find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int x, int y) {
    x = find(x), y = find(y);

    if (depth[x] > depth[y]) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }

    if (depth[x] == depth[y]) {
        depth[y]++;
    }
}

vector<long> dijkstra(int n, int s, vector<vector<long>> &shortest) {
    vector<long> dist(n + 1, -1);
    vector<bool> visited(n + 1, false);
    priority_queue<pair<long, int>, vector<pair<long, int>>> pq;

    dist[s] = 0;
    for (int i = 1; i < s; i++) {
        dist[i] = shortest[i][s];
    }
    pq.emplace(0, s);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u] || u < s) {
            continue;
        }
        visited[u] = true;

        for (auto i : matrix[u]) {
            if (!visited[i.first] && dist[u] != -1 && (dist[i.first] == -1 || dist[u] + i.second < dist[i.first])) {
                dist[i.first] = dist[u] + i.second;
                pq.emplace(-1 * dist[i.first], i.first);
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        matrix.emplace_back();
    }

    for (int i = 0; i < m; i++) {
        int u, v, d, c;
        cin >> u >> v >> d >> c;
        if (d == 0) {
            zero_roads.emplace_back(make_pair(u, v), make_pair(d, c));
        } else {
            non_zero_roads.emplace_back(make_pair(u, v), make_pair(d, c));
        }
        matrix[u].emplace_back(v, d);
        matrix[v].emplace_back(u, d);
    }

    sort(zero_roads.begin(), zero_roads.end(), [](EDGE a, EDGE b) -> bool {
        return a.second.second < b.second.second;
    });

    long total = 0;
    for (int i = 0; i <= n; i++) {
        parent.emplace_back(i);
        depth.emplace_back(0);
    }

    for (auto r : zero_roads) {
        int u = r.first.first;
        int v = r.first.second;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            total += r.second.second;
            merge(set_u, set_v);
        }
    }

    vector<vector<long>> shortest{};
    shortest.emplace_back();
    for (int i = 1; i <= n; i++) {
        vector<long> dist = dijkstra(n, i, shortest);
        shortest.push_back(dist);
    }

    for (auto r : non_zero_roads) {
        long s = -1;
        for (int i = 1; i <= n; i++) {
            int a = r.first.first, b = r.first.second;
            if (a != i && b != i && shortest[a][i] != -1 && shortest[b][i] != -1) {
                if (s == -1) {
                    s = shortest[a][i] + shortest[b][i];
                } else {
                    s = min(shortest[a][i] + shortest[b][i], s);
                }
            }
        }
        if (s == -1 || r.second.first < s) {
            total += r.second.second;
        }
    }

    cout << total << endl;
}