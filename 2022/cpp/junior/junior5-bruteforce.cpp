#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> s{};
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        s.emplace_back(a, b);
    }

    int m = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n - i + 1 && k <= n - j + 1; k++) {
                bool blocked = false;
                for (auto tt : s) {
                    if (tt.first >= i && tt.first < i + k && tt.second >= j && tt.second < j + k) {
                        blocked = true;
                        break;
                    }
                }
                if (!blocked) {
                    m = max(m, k);
                }
            }
        }
    }

    cout << m << endl;
}