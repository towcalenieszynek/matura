#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    int n = pow(2, k);
    vector<int> drz(n);
    for(int i = 1; i < n; i++) {
        cin >> drz[i];
    }
    int p = 0; 
    int suma = 0; 
    int wynik = INT_MAX;


    for (int i = n / 2 + 1; i < n; i++) {
        p = i;
        suma = 0;
        while (p >= 1) {
            suma += drz[p];
            p /= 2;
        }
        wynik = min(wynik, suma);
    }
    cout << wynik;
}