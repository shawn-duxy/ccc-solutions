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

    vector<pair<int, int>> left{}, right{};
    int j = 0;
    for (int i = 0; i < n; i++) {
        int start = j;
        bool swipe = false;
        while (j < i && b[j] == a[i]) {
            j++;
            swipe = true;
        }
        if (swipe) {
            left.emplace_back(start, i);
        }
        swipe = false;
        while (j < n && b[j] == a[i]) {
            j++;
            swipe = true;
        }
        if (swipe && i != j - 1) {
            right.emplace_back(i, j - 1);
        }
    }

    if (j == n) {
        cout << "YES" << endl;
        cout << left.size() + right.size() << endl;
        for (auto it = right.rbegin(); it != right.rend(); ++it) {
            cout << "R " << it->first << " " << it->second << endl;
        }
        for (auto & it : left) {
            cout << "L " << it.first << " " << it.second << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}
