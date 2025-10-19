#include <bits/stdc++.h>
using namespace std;

int main() {
    string w;
    cin >> w;

    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid{};
    for (int i = 0; i < r; i++) {
        vector<char> row{};
        for (int j = 0; j < c; j++) {
            char c;
            cin >> c;
            row.push_back(c);
        }
        grid.push_back(row);
    }

    int count = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == w[0]) {
                bool found = true;
                if (i + w.size() <= r) {
                    for (int k = 1; k < w.size(); k++) {
                        if (grid[i + k][j] != w[k]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        count++;
                    }
                }

                found = true;
                if (i >= w.size() - 1) {
                    for (int k = 1; k < w.size(); k++) {
                        if (grid[i - k][j] != w[k]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        count++;
                    }
                }

                found = true;
                if (j + w.size() <= c) {
                    for (int k = 1; k < w.size(); k++) {
                        if (grid[i][j + k] != w[k]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        count++;
                    }
                }

                found = true;
                if (j >= w.size() - 1) {
                    for (int k = 1; k < w.size(); k++) {
                        if (grid[i][j - k] != w[k]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        count++;
                    }
                }

                found = true;
                if (i + w.size() <= r && j + w.size() <= c) {
                    for (int k = 1; k < w.size(); k++) {
                        if (grid[i + k][j + k] != w[k]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        count++;
                    }
                }

                found = true;
                if (i + w.size() <= r && j >= w.size() - 1) {
                    for (int k = 1; k < w.size(); k++) {
                        if (grid[i + k][j - k] != w[k]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        count++;
                    }
                }

                found = true;
                if (i >= w.size() - 1 && j + w.size() <= c) {
                    for (int k = 1; k < w.size(); k++) {
                        if (grid[i - k][j + k] != w[k]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        count++;
                    }
                }

                found = true;
                if (i >= w.size() - 1 && j >= w.size() - 1) {
                    for (int k = 1; k < w.size(); k++) {
                        if (grid[i - k][j - k] != w[k]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;
}