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
            char ch;
            cin >> ch;
            row.push_back(ch);
        }
        grid.push_back(row);
    }

    int count = 0;

    pair<int, int> offset[8] = {
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1},
        {-1, 0},
        {-1, 1}
    };

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == w[0]) {
                for (int k = 0; k < 8; k++) {
                    string t{grid[i][j]};
                    for (int a = 1; a < w.size(); a++) {
                        int x = i + offset[k].first * a, y = j + offset[k].second * a;
                        if (x >= 0 && x < r && y >= 0 && y < c) {
                            t += grid[x][y];
                        }
                    }
                    if (w == t) {
                        count++;
                    }
                    for (int a = 2; a < w.size(); a++) {
                        t = grid[i][j];
                        for (int b = 1; b < a; b++) {
                            int x = i + offset[k].first * b, y = j + offset[k].second * b;
                            if (x >= 0 && x < r && y >= 0 && y < c)  {
                                t += grid[x][y];
                            }
                        }
                        for (int d = 1; d <= w.size() - a; d++) {
                            int x = i + offset[k].first * (a - 1) + offset[(k + 2) % 8].first * d;
                            int y = j + offset[k].second * (a - 1) + offset[(k + 2) % 8].second * d;
                            if (x >= 0 && x < r && y >= 0 && y < c)  {
                                t += grid[x][y];
                            }
                        }
                        if (w == t) {
                            count++;
                        }
                        t = t.substr(0, a);
                        for (int d = 1; d <= w.size() - a; d++) {
                            int x = i + offset[k].first * (a - 1) + offset[(k + 6) % 8].first * d;
                            int y = j + offset[k].second * (a - 1) + offset[(k + 6) % 8].second * d;
                            if (x >= 0 && x < r && y >= 0 && y < c)  {
                                t += grid[x][y];
                            }
                        }
                        if (w == t) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;
}