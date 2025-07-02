#include <bits/stdc++.h>
using namespace std;

int main() {
    int dusa;
    cin >> dusa;

    while (true) {
        int yobis;
        cin >> yobis;
        if (dusa > yobis) {
            dusa += yobis;
        } else {
            break;
        }
    }

    cout << dusa << endl;
}