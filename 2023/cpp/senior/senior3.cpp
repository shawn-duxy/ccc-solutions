#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r, c;
    cin >> n >> m >> r >> c;

    if (r > 0 && r < n && c > 0 && c < m) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < m; j++) {
                cout << 'a';
            }
            cout << endl;
        }
        for (int i = r; i < n; i++) {
            for (int j = 0; j < c; j++) {
                cout << 'a';
            }
            for (int j = c; j < m; j++) {
                cout << 'b';
            }
            cout << endl;
        }
    }

    vector<vector<char>> result{};
    bool flip = false;
    if (r != 0 && r != n && (c == 0 || c == m)) {
        flip = true;
        swap(r, c);
        swap(n, m);
    }

    if (r == 0) {
        for (int i = 0; i < n - 1; i++) {
            vector<char> row{};
            for (int j = 0; j < m - 1; j++) {
                row.push_back('a');
            }
            row.push_back('b');
            result.push_back(row);
        }
        vector<char> row{};
        for (int i = 0; i < c; i++) {
            row.push_back('a');
        }
        for (int i = c; i < m - 1; i++) {
            row.push_back('b');
        }
        if (c == m) {
            row[m - 1] = 'b';
        }
        if (c < m) {
            row.push_back('c');
        }
        result.push_back(row);
    } else if (r == n) {
        if (c % 2 != 0 && m % 2 == 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        for (int i = 0; i < n; i++) {
            vector<char> row{};
            for (int j = 0; j < m; j++) {
                row.push_back('a');
            }
            result.push_back(row);
        }
        if ((m - c) % 2 == 1) {
            result[0][m / 2] = 'b';
        }
        for (int i = 0; i < (m - c) / 2; i++) {
            result[0][m / 2 - i - 1] = 'b';
            result[0][(m + 1) / 2 + i] = 'b';
        }
    }

    if (flip) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << result[j][i];
            }
            cout << endl;
        }
    } else {
        for (auto &row : result) {
            for (auto &ch : row) {
                cout << ch;
            }
            cout << endl;
        }
    }
}