#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;
vector<bool> odwiedzony;
vector<int> reprezentanci;
int n, m, a, b;

void dfs(int w) {
    odwiedzony[w] = true;
    for (auto sasiad : t[w]) {
        if (!odwiedzony[sasiad]) {
            dfs(sasiad);
        }
    }
}


int main() {
    cin >> n >> m;
    t.resize(n+1);
    odwiedzony.resize(n+1, false);

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!odwiedzony[i]) {
            reprezentanci.push_back(i);
            dfs(i);
        }
    }

    // for (int miasto : reprezentanci) {
    //     cout << miasto << " ";
    // }
    // cout << "\n" << reprezentanci.size();

    cout << reprezentanci.size() - 1 << "\n";
    for(int i = 1; i < reprezentanci.size(); i++) {
        cout << reprezentanci[i-1] << " " << reprezentanci[i] << "\n";
    }
}