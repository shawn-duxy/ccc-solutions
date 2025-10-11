#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long>> chocolate(2, vector<long>(n));

    long long total = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            long v;
            cin >> v;
            chocolate[i][j] = v;
            total += v;
        }
    }

    vector<vector<long>> prefix(2, vector<long>(n + 1));
    prefix[0][0] = 0;
    prefix[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[0][i] = chocolate[0][i - 1] * 2 * n - total + prefix[0][i - 1];
        prefix[1][i] = chocolate[1][i - 1] * 2 * n - total + prefix[1][i - 1];
    }

    unordered_map<long, long> best[4];
    for (int i = 0; i < 4; i++) {
        best[i] = unordered_map<long, long>{};
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                best[i][prefix[k][j]] = LONG_MIN;
            }
        }
    }

    vector<vector<long>> result(2, vector<long>(n + 1));
    result[0][0] = 0;
    result[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 2; k++) {
            best[k][prefix[k][i - 1]] = max(best[k][prefix[k][i - 1]], result[1 - k][i - 1]);
            best[k + 2][prefix[1 - k][i - 1]] = max(best[k + 2][prefix[1 - k][i - 1]], result[k][i - 1]);
        }
        for (int k = 0; k < 2; k++) {
            long parts = max(result[k][i - 1], result[1 - k][i - 1]);
            if (best[1 - k].find(prefix[1 - k][i]) != best[1 - k].end()) {
                parts = max(parts, best[1 - k][prefix[1 - k][i]] + 1);
            }
            if (best[3 - k].find(-1 * prefix[1 - k][i]) != best[3 - k].end()) {
                parts = max(parts, best[3 - k][-1 * prefix[1 - k][i]] + 1);
            }
            result[k][i] = parts;
        }
        if (prefix[0][i] + prefix[1][i] == 0) {
            long m = max(result[0][i], result[1][i]);
            result[0][i] = m + 1;
            result[1][i] = m + 1;
        }
    }

    cout << result[1][n] << endl;
}