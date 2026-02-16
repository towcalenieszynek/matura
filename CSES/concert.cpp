#include <bits/stdc++.h>
using namespace std;

vector<int> tickets, klienci;
// vector<bool> kupione;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    tickets.resize(n);
    // kupione.assign(n, false);
    klienci.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> tickets[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> klienci[i];
    }

    sort(tickets.begin(), tickets.end());

    for(int max_cena : klienci) {
        int pocz = 0;
        int kon = tickets.size() - 1;
        int wynik_idx = -1;
        while (pocz <= kon) {
            int sr = (pocz + kon) / 2;
            if (tickets[sr] <= max_cena) {
                pocz = sr + 1;
                wynik_idx = sr;
            } else {
                kon = sr - 1;
            }
        }
        if (wynik_idx != -1) {
            cout << tickets[wynik_idx] << "\n";
            tickets.erase(tickets.begin() + wynik_idx);
            // kupione[wynik_idx] = true;
        } else {
            cout << -1 << "\n";
        }
    }
}