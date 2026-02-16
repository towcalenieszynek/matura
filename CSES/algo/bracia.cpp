#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> pocz(n+1, -1);
    vector<int> kon(n+1, -1);
    for(int i = 0; i < n; i++) {
        if (pocz[v[i]] == -1) {
            pocz[v[i]] = i;
        }
    }
    int unique = 0;
    for(int j = n-1; j >= 0; j--) {
        if(kon[v[j]] == -1) {
            kon[v[j]] = j;
            unique++;
        }
    }

    for (int k = 1; k <= 3; k++) {
        cout << "Dla " << k << "P i K to " << pocz[k] << " " << kon[k] << "\n";
    }

    int wynik = 0;
    int ostatni_wybrany_koniec = 0;

    for(int i = 0; i < n; i++) {
        if (i == kon[v[i]]) {
            if(pocz[v[i]] > kon[ostatni_wybrany_koniec])
            {
                wynik++;
                ostatni_wybrany_koniec = i;
            }
        }
    }

    cout << wynik << endl;
}