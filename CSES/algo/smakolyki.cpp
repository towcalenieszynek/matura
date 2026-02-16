#include <bits/stdc++.h>
using namespace std;

void wypisz(vector <bool>& v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<bool> smak(k, false);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int kon = 1;
    int wynik = 0;

    for(int pocz = 0; pocz < n; pocz++)
    {
        cout << "dla pocz " << pocz << endl;
        while(kon < n && !smak[v[kon]])
        {
            smak[v[kon]] = true;
            kon++;
        }
        cout << "kon pocz " << kon << " " << pocz << "czyli dodaje do wyniku " << kon - pocz << endl;
        wynik += kon - pocz;
        cout << "stan wektora smak "; wypisz(smak);

        smak[v[pocz]] = false;
    }

    cout << wynik;
}