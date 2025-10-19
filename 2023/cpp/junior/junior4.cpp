#include <bits/stdc++.h>
using namespace std;

int main() {
    int c;
    cin >> c;

    int length = 0;
    vector<vector<bool>> grid(2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < c; j++) {
            int t;
            cin >> t;
            if (t == 1) {
                length += 3;
            }
            grid[i].push_back(t == 1);
        }
    }

    for (int i = 0; i < c; i++) {
        if (i % 2 == 0 && grid[0][i] && grid[1][i]) {
            length -= 2;
        }
        if (i < c - 1 && grid[0][i] && grid[0][i + 1]) {
            length -= 2;
        }
        if (i < c - 1 && grid[1][i] && grid[1][i + 1]) {
            length -= 2;
        }
    }

    cout << length << endl;
}