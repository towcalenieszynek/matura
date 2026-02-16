#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> czy_szczyt; czy_szczyt.push_back(0);
    for (int i = 2; i <= n-1; i++) {
        if (v[i] < v[i-1] && v[i-1] > v[i-2]) 
            czy_szczyt.push_back(1);
        else czy_szczyt.push_back(0);
    }
    czy_szczyt.push_back(0);
    
    cout << "szczyty\n";
    for(int czy : czy_szczyt) {
        cout << czy << " ";
    }
    cout << "\n";





    vector<int> dzielniki;
    // k >= 3, bo na odcinku o dlugosci 2 nie da sie okreslic szczytu
    for(int k = 3; k * k <= n; k++) {
        dzielniki.push_back(k);
    }


    vector<int> pref_szczyty(n,0);
    // BŁAD To ze w tej ponizszej petli czy_szczyt powinien byc tablica sum prefiksowych sluzaca do wylapywania szczytow a nie tablica mowiaca czy pod indeksem jest sczyt@!!!!!
    for (int i = 1; i <= czy_szczyt.size(); i++) {
        pref_szczyty[i] = pref_szczyty[i-1] + czy_szczyt[i-1];
    }



    // // lecimy po dzielnikach - czyli mozliwych dlugosciach odcinkow - od najmniejszych do najwiekszych -> tak sie sklada ze n / k to ilosc flag (bo tyle ile bedzie odcinkow to tyle flag)
    // for (int k : dzielniki) {
    //     bool res = true;
    //     cout << "wchodze do petli dla dzielnika " << k;
    //     for(int i = k; i <= n; i = i + k) {
    //         cout << "zaczynam wewnetrzna petle obecnie " << i << "a wynik odejmowania to dla " << i << " " << k << " = " << czy_szczyt[i] - czy_szczyt[i - k] << endl;
    //         if (!(czy_szczyt[i] - czy_szczyt[i - k] > 0)) {
    //             res = false;
    //             break;
    //         }
    //     }
    //     if (res) {
    //         cout << "wynik to " << k;
    //         break;
    //     }
    // }
    // cout << "NIE";

 // lecimy po dzielnikach - czyli mozliwych dlugosciach odcinkow - od najmniejszych do najwiekszych -> tak sie sklada ze n / k to ilosc flag (bo tyle ile bedzie odcinkow to tyle flag)
    for (int k : dzielniki) {
        bool res = true;
        cout << "wchodze do petli dla dzielnika " << k;
        for(int i = k; i <= n; i = i + k) {
            cout << "zaczynam wewnetrzna petle obecnie " << i << "a wynik odejmowania to dla " << i << " " << k << " = " << pref_szczyty[i] - pref_szczyty[i - k] << endl;
            if (!(pref_szczyty[i] - pref_szczyty[i - k] > 0)) {
                res = false;
                break;
            }
        }
        if (res) {
            cout << "wynik to " << k;
            break;
        }
    }
    cout << "NIE";


}