#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int c = 0;
    for (int i = 0; i < n; i++) {
        int g, f;
        cin >> g >> f;
        if (g * 5 - f * 3 > 40) {
            c++;
        }
    }

    cout << c;
    if (c == n) {
        cout << "+";
    }
    cout << endl;
}