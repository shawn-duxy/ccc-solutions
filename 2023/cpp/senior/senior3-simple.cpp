#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r, c;
    cin >> n >> m >> r >> c;

    if (r == 1 && c == 1) {
        for (int i = 0; i < m; i++) {
            cout << 'a';
        }
        cout << endl;
        for (int i = 1; i < n; i++) {
            cout << 'a';
            for (int j = 1; j < m; j++) {
                cout << 'b';
            }
            cout << endl;
        }
    } else if (n == 2 && m == 2) {
        if (r == 0 && c == 0) {
            cout << "ab" << endl << "cd" << endl;
        } else if (r == 0 && c == 1) {
            cout << "ab" << endl << "ac" << endl;
        } else if (r == 1 && c == 0) {
            cout << "aa" << endl << "cd" << endl;
        } else if (r == 1 && c == 1) {
            cout << "aa" << endl << "ac" << endl;
        } else if (r == 0 && c == 2) {
            cout << "ab" << endl << "ab" << endl;
        } else if (r == 2 && c == 0) {
            cout << "aa" << endl << "bb" << endl;
        } else if (r == 1 && c == 2) {
            cout << "IMPOSSIBLE" << endl;
        } else if (r == 2 && c == 1) {
            cout << "IMPOSSIBLE" << endl;
        } else if (r == 2 && c == 2) {
            cout << "aa" << endl << "aa" << endl;
        }
    }
}