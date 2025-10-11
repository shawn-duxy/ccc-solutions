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

    vector<vector<long>> result(2, vector<long>(n + 1));
    result[0][0] = 0;
    result[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 2; k++) {
            long parts = max(result[k][i - 1], result[1 - k][i - 1]);
            for (int j = 0; j < i; j++) {
                if (prefix[1 - k][j] == prefix[1 - k][i]) {
                    parts = max(parts, result[k][j] + 1);
                }
            }
            for (int j = 1; j < i; j++) {
                if (prefix[1 - k][i] + prefix[k][j] == 0) {
                    parts = max(parts, result[1 - k][j] + 1);
                }
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