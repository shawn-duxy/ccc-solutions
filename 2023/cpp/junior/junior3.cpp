#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(5, 0);
    int m = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            if (s[j] == 'Y') {
                d[j]++;
                m = max(m, d[j]);
            }
        }
    }

    string r = "";
    for (int i = 0; i < 5; i++) {
        if (d[i] == m) {
            if (r.size() > 0) {
                r += ",";
            }
            r += to_string(i + 1);
        }
    }

    cout << r << endl;
}