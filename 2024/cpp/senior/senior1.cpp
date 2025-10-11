#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> hats{};

    cin >> n;

    int h;
    for (int i = 0; i < n; i++) {
        cin >> h;
        hats.push_back(h);
    }

    int total = 0;
    for (int i = 0; i < n / 2; i++) {
        if (hats[i] == hats[i + n / 2]) {
            total += 2;
        }
    }

    cout << total << endl;
}
