#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = t;
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b[i] = t;
    }

    vector<pair<char, pair<int, int>>> allSwipes{};
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                allSwipes.push_back({k == 0 ? 'R' : 'L', {i, j}});
            }
        }
    }

    set<vector<int>> visited{};
    vector<tuple<vector<int>, int, int>> steps{};
    visited.insert(a);
    steps.emplace_back(a, -1, -1);
    int current = 0;
    while (steps.size() > current) {
        auto c = steps[current];
        if (get<0>(c) == b) {
            cout << "YES" << endl;
            vector<pair<char, pair<int, int>>> swipes{};
            while (get<1>(c) >= 0) {
                swipes.push_back(allSwipes[get<2>(c)]);
                c = steps[get<1>(c)];
            }
            cout << swipes.size() << endl;
            for (int i = swipes.size() - 1; i >= 0; i--) {
                cout << swipes[i].first << ' ' << swipes[i].second.first << ' ' << swipes[i].second.second << endl;
            }
            return 0;
        }
        for (int i = 0; i < allSwipes.size(); i++) {
            auto swipe = allSwipes[i];
            vector<int> next = get<0>(c);
            for (int j = swipe.second.first; j <= swipe.second.second; j++) {
                if (swipe.first == 'R') {
                    next[j] = next[swipe.second.first];
                } else {
                    next[j] = next[swipe.second.second];
                }
            }
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                steps.emplace_back(next, current, i);
            }
        }
        current++;
    }

    cout << "NO" << endl;
}
