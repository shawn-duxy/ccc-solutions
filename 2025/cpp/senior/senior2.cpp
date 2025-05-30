#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  long total = 0;
  long current = 0;
  for (char c : s) {
    if (isalpha(c)) {
      total += current;
      current = 0;
    } else {
      current = current * 10 + c - '0';
    }
  }
  total += current;

  long c;
  cin >> c;
  long r = c % total;

  current = 0;
  char last = s[0];
  char letter = 0;
  for (char ch : s) {
    if (isalpha(ch)) {
      letter = ch;
      r -= current;
      current = 0;
      if (r < 0) {
        cout << last << endl;
        return 0;
      }
      last = letter;
    } else {
      current = current * 10 + ch - '0';
    }
  }
  cout << letter << endl;
}
