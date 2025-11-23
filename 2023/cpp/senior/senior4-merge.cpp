#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> EDGE;

vector<int> depth{};
vector<int> parent{};
vector<EDGE> zero_roads{};
vector<unordered_set<int>> groups{};
vector<unordered_map<int, pair<int, int>>> matrix{};

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
            if (!visited[i.first] && dist[u] != -1 && (dist[i.first] == -1 || dist[u] + i.second.first < dist[i.first])) {
                dist[i.first] = dist[u] + i.second.first;
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
            int pos_u = -1, pos_v = -1;
            for (int j = 0; j < groups.size(); j++) {
                if (groups[j].find(u) != groups[j].end()) {
                    pos_u = j;
                }
                if (groups[j].find(v) != groups[j].end()) {
                    pos_v = j;
                }
            }
            if (pos_u == -1 && pos_v == -1) {
                unordered_set<int> group{};
                group.emplace(u);
                group.emplace(v);
                groups.push_back(group);
            } else if (pos_u != -1 && pos_v != -1 && pos_u != pos_v) {
                for (auto g : groups[pos_v]) {
                    groups[pos_u].emplace(g);
                }
                groups.erase(groups.begin() + pos_v);
            } else if (pos_u != -1 && pos_v == -1) {
                groups[pos_u].emplace(v);
            } else if (pos_v != -1 && pos_u == -1) {
                groups[pos_v].emplace(u);
            }
        } else {
            if (matrix[u].find(v) == matrix[u].end()) {
                matrix[u].emplace(v, make_pair(d, c));
                matrix[v].emplace(u, make_pair(d, c));
            } else if (matrix[u][v].first > d || (matrix[u][v].first == d && matrix[u][v].second > c)) {
                matrix[u][v] = make_pair(d, c);
                matrix[v][u] = make_pair(d, c);
            }
        }
    }

    for (auto g : groups) {
        int u = *g.begin();
        for (int i : g) {
            if (u == i) {
                continue;
            }
            for (auto [v, d] : matrix[i]) {
                if (g.find(v) == g.end()) {
                    if (matrix[u].find(v) == matrix[u].end()) {
                        matrix[u].emplace(v, d);
                        matrix[v].emplace(u, d);
                    } else if (matrix[u][v].first > d.first || (matrix[u][v].first == d.first && matrix[u][v].second > d.second)) {
                        matrix[u][v] = d;
                        matrix[v][u] = d;
                    }
                }
                matrix[v].erase(i);
            }
            matrix[i].clear();
        }
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

    for (int u = 1; u <= n; u++) {
        for (auto [v, d] : matrix[u]) {
            if (v < u) {
                continue;
            }
            long s = -1;
            for (int i = 1; i <= n; i++) {
                if (u != i && v != i && shortest[u][i] != -1 && shortest[v][i] != -1) {
                    if (s == -1) {
                        s = shortest[u][i] + shortest[v][i];
                    } else {
                        s = min(shortest[u][i] + shortest[v][i], s);
                    }
                }
            }
            if (s == -1 || d.first < s) {
                total += d.second;
            }
        }
    }

    cout << total << endl;
}