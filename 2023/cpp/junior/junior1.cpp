#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, c;

    cin >> p >> c;

    int points = p * 50 - c * 10;
    if (p > c) {
        points += 500;
    }

    cout << points << endl;
}