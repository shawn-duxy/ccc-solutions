#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int c = 0;
    for (int i = 0; i <= n / 5; i++) {
        if ((n - 5 * i) % 4 == 0) {
            c++;
        }
    }
    cout << c << endl;
}