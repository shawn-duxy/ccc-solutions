#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<string, int>> weather{};
  string current;
  cin >> current;
  int count = 1;
  for (int i = 1; i < n; i++) {
    string w;
    cin >> w;
    if (current == w) {
      count++;
    } else {
      weather.emplace_back(current, count);
      current = w;
      count = 1;
    }
  }
  weather.emplace_back(current, count);

  if (weather.size() == 1 && weather[0].first == "S") {
    cout << weather[0].second - 1;
    return 0;
  }

  int ans = 1;
  for (int i = 0; i < weather.size(); i++) {
    if (weather[i].first == "S") {
      ans = max(ans, weather[i].second);
    } else if (weather[i].first == "P" && weather[i].second == 1) {
      int total = 1;
      if (i > 0) {
        total += weather[i - 1].second;
      }
      if (i < weather.size() - 1) {
        total += weather[i + 1].second;
      }
      ans = max(ans, total);
    } else {
      if (i > 0) {
        ans = max(ans, weather[i - 1].second + 1);
      }
      if (i < weather.size() - 1) {
        ans = max(ans, weather[i + 1].second + 1);
      }
    }
  }

  cout << ans;
}
