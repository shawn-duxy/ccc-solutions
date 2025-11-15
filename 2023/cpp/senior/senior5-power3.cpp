#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> answers{};
    answers.emplace_back(0);
    answers.emplace_back(1);

    int a = 3;
    while (n > 1) {
        n /= 3;
        for (int i = answers.size() - 1; i >= 0; --i) {
            answers.emplace_back(a - answers[i]);
        }
        a *= 3;
    }

    for (int a : answers) {
        cout << a << endl;
    }
}