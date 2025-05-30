#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;

  int area1 = (a + x) + max(b, y);
  int area2 = (b + y) + max(a, x);

  cout << 2 * min(area1, area2);
}
