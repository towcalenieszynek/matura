#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> sz(n);
    for(int i = 0; i < n; i++) {
        cin >> sz[i];
    }
    int suma = 0;
    int wynik = 0;
    for (int i = 0; i < n; i++) {
        suma += sz[i];
        if (suma >= w) {
            wynik++; 
            suma = 0;            
        }
    }
    cout << wynik;
}
