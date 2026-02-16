#include <bits/stdc++.h>
using namespace std;

int znajdz_lidera(const vector<int>& v)
{
    int kandytat = -1;
    int licznik = 0;
    for (int liczba : v) {
        if(licznik == 0) {
            kandytat = liczba;
            licznik++;
        }
        else {
            if (kandytat == liczba) {
                licznik++;
            }
            else {
                licznik--;
            }
        }
    }

    licznik = 0;
    for (int liczba : v) {
        if (liczba == kandytat) {
            licznik++;
        }
    }

    if (licznik*2 > v.size()) {
        return kandytat;
    } else {
        return -1;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int lider = znajdz_lidera(a);

    vector<int> pr(n);
    pr[0] = (a[0] == lider);
    for (int i = 1; i < n; i++) {
        pr[i] = (a[i] == lider) + pr[i-1]; 
    }

    int licznik = 0;

    for (int i = 0; i < n; i++) {
        if (pr[i] > (i+1)/2) licznik++;
        if (2*licznik > n) break;
    }

    if (2*licznik > n) {
        cout << lider;
    } else {
        cout << "NIE";
    }


}