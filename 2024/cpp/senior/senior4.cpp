#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>>> & roads, set<int> & visited, vector<char> & colors, int vertex, bool useRed) {
    visited.insert(vertex);
    for (auto road : roads[vertex]) {
        if (visited.find(road.first) == visited.end()) {
            if (useRed) {
                colors[road.second] = 'R';
            } else {
                colors[road.second] = 'B';
            }
            dfs(roads, visited, colors, road.first, !useRed);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> roads(n + 1);
    vector<char> colors(m, 'G');
    set<int> visited{};

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        roads[a].emplace_back(b, i);
        roads[b].emplace_back(a, i);
    }

    for (int i = 1; i <= n; i++) {
        dfs(roads, visited, colors, i, true);
    }

    for (char c : colors) {
        cout << c;
    }
    cout << endl;
}
