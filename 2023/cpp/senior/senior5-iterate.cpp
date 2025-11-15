#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> answers{};
    answers.emplace_back(0);

    for (int i = 1; i <= n; i++) {
        unordered_map<int, bool> s;
        s.emplace(0, false);
        s.emplace(n, false);
        int a = i;
        bool covered = false;
        while (true) {
            if (3 * a <= n) {
                a *= 3;
                if (s[a]) {
                    covered = false;
                    break;
                }
                s[a] = true;
            } else if (3 * a >= n * 2) {
                a *= 3;
                a -= n * 2;
                if (s[a]) {
                    covered = false;
                    break;
                }
                s[a] = true;
            } else {
                covered = true;
                break;
            }
        }
        if (!covered) {
            answers.emplace_back(i);
        }
    }

    for (int i : answers) {
        cout << i << endl;
    }
}