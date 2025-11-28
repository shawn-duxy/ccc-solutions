#include <bits/stdc++.h>
using namespace std;

int find(pair<int, int> a, pair<int, int> b, vector<pair<int, int>> &s) {
    int m = 0;
    for (auto t : s) {
        if (t.first >= a.first && t.first <= b.first && t.second >= a.second && t.second <= b.second) {
            if (t.first > a.first) {
                m = max(m, find(a, make_pair(t.first - 1, b.second), s));
            }
            if (t.first < b.first) {
                m = max(m, find(make_pair(t.first + 1, a.second), b, s));
            }
            if (t.second > a.second) {
                m = max(m, find(a, make_pair(b.first, t.second - 1), s));
            }
            if (t.second < b.first) {
                m = max(m, find(make_pair(a.first, t.second + 1), b, s));
            }
        }
    }
    if (m == 0) {
        return min(b.first - a.first, b.second - a.second) + 1;
    } else {
        return m;
    }
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> s{};
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        s.emplace_back(a, b);
    }

    int m = find(make_pair(1, 1), make_pair(n, n), s);
    cout << m << endl;
}