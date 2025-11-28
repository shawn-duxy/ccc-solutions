#include <bits/stdc++.h>
using namespace std;

int find(int r, int c, int n, vector<pair<int, int>> &s) {
    int mh = n - r, mw = n - c;
    for (auto t : s) {
        if (t.first > r && t.second > c) {
            int dr = t.first - r - 1, dc = t.second - c - 1;
            if (dr > dc) {
                mh = min(mh, dr);
            } else {
                mw = min(mw, dc);
            }
        }
    }
    return min(mh, mw);
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

    vector<int> r{}, c{};
    r.push_back(0);
    c.push_back(0);
    for (auto t : s) {
        r.push_back(t.first);
        c.push_back(t.second);
    }

    int m = 0;
    for (int i : r) {
        for (int j : c) {
            m = max(m, find(i, j, n, s));
        }
    }

    cout << m << endl;
}