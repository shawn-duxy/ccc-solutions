#include <bits/stdc++.h>
using namespace std;

unordered_set<int> numbers{};
const int N = pow(3, 19);

void fill(int a, int n, int k) {
    if (k >= N) {
        for (int i = (long) a * n / k; i <= (long) (a + 1) * n / k; i++) {
            numbers.insert(i);
        }
    } else {
        fill(a * 3, n, k * 3);
        fill(a * 3 + 2, n, k * 3);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    fill(0, n, 1);

    vector<int> answers{};
    for (int i : numbers) {
        unordered_set<int> s;
        s.insert(0);
        s.insert(n);
        long a = i;
        bool covered = false;
        while (true) {
            if (3 * a <= n) {
                a *= 3;
                if (s.find(a) != s.end()) {
                    covered = false;
                    break;
                }
                s.insert(a);
            } else if (3 * a >= n * 2) {
                a = a * 3 - n * 2;
                if (s.find(a) != s.end()) {
                    covered = false;
                    break;
                }
                s.insert(a);
            } else {
                covered = true;
                break;
            }
        }
        if (!covered) {
            answers.emplace_back(i);
        }
    }

    sort(answers.begin(), answers.end());
    for (int i : answers) {
        cout << i << endl;
    }
}