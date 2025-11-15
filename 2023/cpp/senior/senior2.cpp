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

    for (int i = 1; i < n; i++) {
        int s = i - 1, e = i;
        int d = abs(v[e] - v[s]);
        if (result[e - s] > d) {
            result[e - s] = d;
        }
        while (s > 0 && e < n - 1) {
            s--;
            e++;
            d += abs(v[e] - v[s]);
            if (result[e - s] > d) {
                result[e - s] = d;
            }
        }
        if (i < n - 1) {
            s = i - 1, e = i + 1;
            d = abs(v[e] - v[s]);
            if (result[e - s] > d) {
                result[e - s] = d;
            }
            while (s > 0 && e < n - 1) {
                s--;
                e++;
                d += abs(v[e] - v[s]);
                if (result[e - s] > d) {
                    result[e - s] = d;
                }
            }
        }
    }

    cout << result[0];
    for (int i = 1; i < n; i++) {
        cout << ' ' << result[i];
    }
}