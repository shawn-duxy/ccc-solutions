#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &patch, set<pair<int, int>> &visited, int r, int c, int a, int b) {
    int total = patch[a][b];
    visited.insert({a, b});
    if (a > 0 && patch[a - 1][b] != -1 && visited.find({a - 1, b}) == visited.end()) {
        total += dfs(patch, visited, r, c, a - 1, b);
    }
    if (a < r - 1 && patch[a + 1][b] != -1 && visited.find({a + 1, b}) == visited.end()) {
        total += dfs(patch, visited, r, c, a + 1, b);
    }
    if (b > 0 && patch[a][b - 1] != -1 && visited.find({a, b - 1}) == visited.end()) {
        total += dfs(patch, visited, r, c, a, b - 1);
    }
    if (b < c - 1 && patch[a][b + 1] != -1 && visited.find({a, b + 1}) == visited.end()) {
        total += dfs(patch, visited, r, c, a, b + 1);
    }
    return total;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> patch(r);
    for (int i = 0; i < r; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < c; j++) {
            switch (row[j]) {
                case 'S':
                    patch[i].push_back(1);
                    break;
                case 'M':
                    patch[i].push_back(5);
                    break;
                case 'L':
                    patch[i].push_back(10);
                    break;
                default:
                    patch[i].push_back(-1);
            }
        }
    }
    int a, b;
    cin >> a >> b;

    set<pair<int, int>> visited;
    int total = dfs(patch, visited, r, c, a, b);

    cout << total << endl;
}
