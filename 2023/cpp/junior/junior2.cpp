#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int spiciness = 0;
    for (int i = 0; i < n; i++) {
        string pepper;
        cin >> pepper;
        if (pepper == "Poblano") {
            spiciness += 1500;
        } else if (pepper == "Mirasol") {
            spiciness += 6000;
        } else if (pepper == "Serrano") {
            spiciness += 15500;
        } else if (pepper == "Cayenne") {
            spiciness += 40000;
        } else if (pepper == "Thai") {
            spiciness += 75000;
        } else if (pepper == "Habanero") {
            spiciness += 125000;
        }
    }

    cout << spiciness << endl;
}