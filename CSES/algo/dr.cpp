#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, k;
    cin >> p >> k;
    int wynik = 0;
    while (p != k) {
        if (p > 1) {
            p /= 2;
            wynik++;
        }
        if (k > 1) {
            k /= 2;
            wynik++;
        }
    }
    cout << wynik;
}