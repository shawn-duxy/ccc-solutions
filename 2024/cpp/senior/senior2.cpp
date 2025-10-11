#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t >> n;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        set<char> heavy{};
        set<char> light{};

        for (char c : s) {
            if (light.find(c) != light.end()) {
                heavy.insert(c);
                light.erase(c);
            } else if (heavy.find(c) == heavy.end()) {
                light.insert(c);
            }
        }

        bool isLight = light.find(s[0]) != light.end();
        bool fail = false;
        for (unsigned int j = 1; j < s.length(); j++) {
            if (isLight && heavy.find(s[j]) == heavy.end()) {
                cout << "F" << endl;
                fail = true;
                break;
            }
            if (!isLight && light.find(s[j]) == light.end()) {
                cout << "F" << endl;
                fail = true;
                break;
            }
            isLight = !isLight;
        }
        if (!fail) {
            cout << "T" << endl;
        }
    }
}
