#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cena;
    cin >> n;
    vector<pair<int, int>> v;
    for (int prof = 0; prof < 3; prof++) {
        for(int i = 1; i <= n; i++) {
            cin >> cena;
            v.push_back({cena, i});
        }
    }

    vector<int> wystapienia(n+1, 0);
    // for(auto el : v) {
    //     cout << el.first << " " << el.second << "\n";
    // }

    sort(v.begin(), v.end());

    // for(auto el : v) {
    //     cout << el.first << " " << el.second << "\n";
    // }

    int L = 0;
    int ile = 0;
    int min_roznica = INT_MAX;

    for(int R = 0; R < 3*n; R++) {
        wystapienia[v[R].second]++;
        if (wystapienia[v[R].second] == 1) {
            ile++;
        }
        while (ile == n) {
            min_roznica = min(min_roznica, (v[R].first - v[L].first));
            wystapienia[v[L].second]--;
            if (wystapienia[v[L].second] == 0) {
                ile--;
            }
            L++;
        }
    }
    cout << min_roznica;
}