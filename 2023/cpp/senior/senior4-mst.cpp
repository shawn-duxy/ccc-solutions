#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, pair<int, int>> EDGE;

vector<int> depth{};
vector<int> parent{};

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<EDGE> roads{};
    for (int i = 0; i < m; i++) {
        int u, v, d, c;
        cin >> u >> v >> d >> c;
        roads.emplace_back(make_pair(u, v), make_pair(d, c));
    }

    sort(roads.begin(), roads.end(), [](EDGE a, EDGE b) -> bool {
        return a.second.second < b.second.second;
    });

    long total = 0;
    for (int i = 0; i <= n; i++) {
        parent.emplace_back(i);
        depth.emplace_back(0);
    }

    for (auto r : roads) {
        int u = r.first.first;
        int v = r.first.second;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            total += r.second.second;
            merge(set_u, set_v);
        }
    }

    cout << total << endl;
}