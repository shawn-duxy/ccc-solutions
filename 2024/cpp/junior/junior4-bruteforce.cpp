#include <bits/stdc++.h>
using namespace std;

int main() {
    string input, output;
    cin >> input;
    cin >> output;

    for (char a = 'a'; a <= 'z'; a++) {
        if (input.find(a) == string::npos) {
            continue;
        }
        for (char b = 'a'; b <= 'z'; b++) {
            if (a != b && output.find(b) != string::npos) {
                string temp1 = input;
                replace(temp1.begin(), temp1.end(), a, b);
                if (input.length() > output.length()) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c != a && c != b && temp1.find(c) != string::npos) {
                            string temp2 = temp1;
                            temp2.erase(remove(temp2.begin(), temp2.end(), c), temp2.end());
                            if (temp2 == output) {
                                cout << a << " " << b << endl;
                                cout << c << endl;
                                a = 'z', b = 'z';
                                break;
                            }
                        }
                    }
                } else {
                    if (temp1 == output) {
                        cout << a << " " << b << endl;
                        cout << "-" << endl;
                        a = 'z', b = 'z';
                        break;
                    }
                }
            }
        }
    }
}