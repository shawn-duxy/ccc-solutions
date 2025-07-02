#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int scores[76];
    fill_n(scores, 76, 0);
    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        scores[score]++;
    }

    int pos = 0;
    for (int i = 75; i >= 0; i--) {
        if (scores[i] > 0) {
            pos++;
        }
        if (pos == 3) {
            cout << i << ' ' << scores[i] << endl;
            break;
        }
    }
}