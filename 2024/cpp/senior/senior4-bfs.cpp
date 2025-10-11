#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> roads(n + 1);
    vector<tuple<int, int, char>> colors{};

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        roads[a].emplace_back(b, i);
        roads[b].emplace_back(a, i);
        colors.emplace_back(a, b, 'G');
    }

    // case #1
    bool hamiltonian = true;
    vector<char> hamiltonColors(m, 'G');
    char color = 'R';
    for (int i = 1; i < n; i++) {
        bool found = false;
        for (int j = 0; j < roads[i].size(); j++) {
            if (roads[i][j].first == i + 1) {
                hamiltonColors[roads[i][j].second] = color;
                color = color == 'R' ? 'B' : 'R';
                found = true;
                break;
            }
        }
        if (!found) {
            hamiltonian = false;
        }
    }
    if (hamiltonian) {
        for (char c : hamiltonColors) {
            cout << c;
        }
        cout << endl;
        return 0;
    }

    vector<tuple<int, int, int>> parent(n + 1);
    set<int> visited{};
    deque<int> q{};
    for (int i = 1; i <= n; i++) {
        if (visited.find(i) == visited.end()) {
            visited.insert(i);
            q.push_back(i);
            parent[i] = {-1, -1, 0};
            while (q.size() > 0) {
                int c = q[0];
                q.pop_front();
                for (int j = 0; j < roads[c].size(); j++) {
                    auto road = roads[c][j];
                    if (visited.find(road.first) == visited.end()) {
                        visited.insert(road.first);
                        q.push_back(road.first);
                        get<2>(colors[road.second]) = 'X';
                        parent[road.first] = {c, j, get<2>(parent[c]) + 1};
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (get<2>(colors[i]) == 'G') {
            char color = 'R';
            int s = get<0>(colors[i]);
            int e = get<1>(colors[i]);
            while (get<2>(parent[s]) > get<2>(parent[e])) {
                int c = get<0>(parent[s]);
                int j = get<1>(parent[s]);
                get<2>(colors[roads[c][j].second]) = color;
                color = color == 'R' ? 'B' : 'R';
                s = get<0>(parent[s]);
            }
            if (get<2>(parent[e]) > get<2>(parent[s])) {
                while (get<2>(parent[e]) > get<2>(parent[s])) {
                    int c = get<0>(parent[e]);
                    int j = get<1>(parent[e]);
                    get<2>(colors[roads[c][j].second]) = color;
                    color = color == 'R' ? 'B' : 'R';
                    e = get<0>(parent[e]);
                }
                color = color == 'R' ? 'B' : 'R';
            }
            while (s != e) {
                int c = get<0>(parent[s]);
                int j = get<1>(parent[s]);
                get<2>(colors[roads[c][j].second]) = color;
                color = color == 'R' ? 'B' : 'R';
                c = get<0>(parent[e]);
                j = get<1>(parent[e]);
                get<2>(colors[roads[c][j].second]) = color;
                s = get<0>(parent[s]);
                e = get<0>(parent[e]);
            }
        }
    }

    for (auto c : colors) {
        if (get<2>(c) == 'X') {
            cout << 'R';
        } else {
            cout << get<2>(c);
        }
    }
    cout << endl;
}
