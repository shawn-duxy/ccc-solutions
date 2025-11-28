#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool end = false;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch >= 'A' && ch <= 'Z') {
            if (end) {
                cout << endl;
            }
            end = false;
            cout << ch;
        }
        if (ch == '-') {
            cout << " loosen ";
        }
        if (ch == '+') {
            cout << " tighten ";
        }
        if (ch >= '0' && ch <= '9') {
            cout << ch;
            end = true;
        }
    }
}