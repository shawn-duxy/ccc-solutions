#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, e, q;

  cin >> d >> e;

  for (int i = 0; i < e; i++) {
    string op;
    cin >> op >> q;
    if (op == "+") {
      d += q;
    } else {
      d -= q;
    }
  }

  cout << d << endl;
}
