#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    sort(scores.begin(), scores.end());
    int pos = 0;
    int score = 0;
    int count = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (pos != 3) {
            if (scores[i] != score) {
                pos++;
                score = scores[i];
            }
        } else if (scores[i] == score) {
            count++;
        } else {
            break;
        }
    }

    cout << score << ' ' << count << endl;
}