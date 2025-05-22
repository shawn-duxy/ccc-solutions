#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int total = 0, current = 0;
    string uppercases = "";
    bool negative = false;

    for (auto c : s) {
      if (isalpha(c)) {
        if (negative) {
          total -= current;
        } else {
          total += current;
        }
        current = 0;
        negative = false;
        if (isupper(c)) {
          uppercases += c;
        }
      } else if (c == '-') {
        if (negative) {
          total -= current;
        } else {
          total += current;
        }
        current = 0;
        negative = true;
      } else {
        current = current * 10 + (c - '0');
      }
    }
    if (negative) {
      total -= current;
    } else {
      total += current;
    }

    cout << uppercases << total << endl;
  }
}
