#include <bits/stdc++.h>
using namespace std;

int main() {
    string input, output;
    cin >> input;
    cin >> output;

    vector<char> mismatch;
    char extra = ' ';
    bool hasSilent = input.length() > output.length();
    vector<int> inputCount(26), outputCount(26);
    for (char c : input) {
        inputCount[c - 'a']++;
    }
    for (char c : output) {
        outputCount[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (inputCount[i] > outputCount[i]) {
            mismatch.push_back('a' + i);
        }
        if (inputCount[i] < outputCount[i]) {
            extra = 'a' + i;
        }
    }
    replace(input.begin(), input.end(), mismatch[0], extra);
    if (hasSilent) {
        input.erase(remove(input.begin(), input.end(), mismatch[1]), input.end());
    }
    if (input == output) {
        cout << mismatch[0] << " " << extra << endl;
        if (hasSilent) {
            cout << mismatch[1] << endl;
        } else {
            cout << "-" << endl;
        }
    } else {
        cout << mismatch[1] << " " << extra << endl;
        cout << mismatch[0] << endl;
    }
}