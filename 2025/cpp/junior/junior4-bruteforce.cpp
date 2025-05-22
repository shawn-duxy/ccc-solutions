#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  string weather = "";
  for (int i = 0; i < n; i++) {
    string w;
    cin >> w;
    weather += w;
  }

  int ans = 0;
  bool containsP = false;
  for (int i = 0; i < weather.size(); i++) {
    if (weather[i] == 'P') {
      containsP = true;
      int sBefore = 0, sAfter = 0;
      int j = i - 1;
      while (j >= 0 && weather[j] == 'S') {
        sBefore++;
        j--;
      }
      j = i + 1;
      while (j < weather.size() && weather[j] == 'S') {
        sAfter++;
        j++;
      }
      ans = max(ans, sBefore + 1 + sAfter);
    }
  }

  if (containsP) {
    cout << ans;
  } else {
    cout << n - 1;
  }
}

