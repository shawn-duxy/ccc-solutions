#include <bits/stdc++.h>
using namespace std;

struct EDGE {
    int x, y, d, c;
};

vector<int> parent{};
vector<EDGE> roads{};
vector<unordered_set<int>> groups{};
vector<vector<pair<int, int>>> matrix{};

int find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

long dijkstra(int n, int s, int e) {
    vector<long> dist(n + 1, -1);
    unordered_set<int> visited{};
    priority_queue<pair<long, int>, vector<pair<long, int>>> pq;

    dist[s] = 0;
    pq.emplace(0, s);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited.find(u) != visited.end()) {
            continue;
        }
        visited.insert(u);

        for (auto i : matrix[u]) {
            if (visited.find(i.first) == visited.end() && (dist[i.first] == -1 || dist[u] + i.second < dist[i.first])) {
                dist[i.first] = dist[u] + i.second;
                pq.emplace(-1 * dist[i.first], i.first);
            }
        }
    }

    return dist[e];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, d, c;
        cin >> u >> v >> d >> c;
        roads.emplace_back(EDGE{u, v, d, c});
    }

    sort(roads.begin(), roads.end(), [](EDGE a, EDGE b) -> bool {
        if (a.d != b.d) {
            return a.d < b.d;
        }
        return a.c < b.c;
    });

    long total = 0;
    for (int i = 0; i <= n; i++) {
        parent.emplace_back(i);
        matrix.emplace_back();
    }

    for (auto r : roads) {
        int u = r.x;
        int v = r.y;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            parent[set_u] = set_v;
            total += r.c;
            matrix[u].emplace_back(v, r.d);
            matrix[v].emplace_back(u, r.d);
        } else if (r.d < dijkstra(n, u, v)) {
            total += r.c;
            matrix[u].emplace_back(v, r.d);
            matrix[v].emplace_back(u, r.d);
        }
    }

    cout << total << endl;
}