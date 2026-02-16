#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int b, p;
    cin >> p;
    int wynik = 2 * (p+1);
    for (int a = 2; a * a <= p; a++) {
        if (p%a == 0) {
            b = p / a;
            wynik = min(wynik, 2*(a+b));
        }
    }

    cout << wynik;
}