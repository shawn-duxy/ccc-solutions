#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v{};
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        v.push_back(h);
    }

    vector<int> result{};
    result.push_back(0);
    for (int i = 1; i < n; i++) {
        result.push_back(INT32_MAX);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = 0;
            for (int k = 0; k < (j - i + 1) / 2; k++) {
                s += abs(v[i + k] - v[j - k]);
            }
            if (result[j - i] > s) {
                result[j - i] = s;
            }
        }
    }

    cout << result[0];
    for (int i = 1; i < n; i++) {
        cout << ' ' << result[i];
    }
}