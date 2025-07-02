#include <bits/stdc++.h>
using namespace std;

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

    int total = 0;
    set<pair<int, int>> visited;
    deque<pair<int, int>> toVisit;
    toVisit.emplace_back(a, b);
    while (!toVisit.empty()) {
        pair<int, int> next = toVisit.front();
        if (visited.find({next.first, next.second}) != visited.end()) {
            toVisit.pop_front();
            continue;
        }
        visited.insert(next);
        toVisit.pop_front();
        total += patch[next.first][next.second];
        if (next.first > 0 && patch[next.first - 1][next.second] != -1 && visited.find({next.first - 1, next.second}) == visited.end()) {
            toVisit.emplace_back(next.first - 1, next.second);
        }
        if (next.first < r - 1 && patch[next.first + 1][next.second] != -1 && visited.find({next.first + 1, next.second}) == visited.end()) {
            toVisit.emplace_back(next.first + 1, next.second);
        }
        if (next.second > 0 && patch[next.first][next.second - 1] != -1 && visited.find({next.first, next.second - 1}) == visited.end()) {
            toVisit.emplace_back(next.first, next.second - 1);
        }
        if (next.second < c - 1 && patch[next.first][next.second + 1] != -1 && visited.find({next.first, next.second + 1}) == visited.end()) {
            toVisit.emplace_back(next.first, next.second + 1);
        }
    }

    cout << total << endl;
}