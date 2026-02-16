#include <bits/stdc++.h>
using namespace std;

vector<bool> odwiedzony;
vector<vector<int>> t;

void DFS(int v) {
    odwiedzony[v] = true;
    // for(int i = 0; i < t[v].size(); i++) {
    //     if (!odwiedzony[t[v][i]]) {
    //         DFS(t[v][i]);
    //     }
    // }
    for (int sasiad : t[v]) {
        if (!odwiedzony[sasiad]) {
            DFS(sasiad);
        }
    }
}   

void BFS(int startowy) {
    vector<int> kolejka;
    kolejka.push_back(startowy);
    odwiedzony[startowy] = true;
    for (int i = 0; i < kolejka.size(); i++) {
        int w = kolejka[i];
        for (int j = 0; j < t[w].size(); j++) {
            if (!odwiedzony[t[w][j]]) {
                kolejka.push_back(t[w][j]);
                odwiedzony[t[w][j]] = true;
            }
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m; // n - ilosc wierzcholkow // m - ilosc krawedzi
    odwiedzony.assign(n+1, false);

    /*implementacja macierzy sasiedztwa*/
    int tab[n][n];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        tab[a][b]++;
        tab[b][a]++; // tylko dla grafu nieskierowanego
    }
    /*implementacja listy sasiedztwa - bardziej optymalne pamieciowo*/
    // vector<int> t[n];
    t.resize(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a); // tylko dla grafu nieskierowanego
    }
}