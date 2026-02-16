#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t(100007);
vector<int> druzyna(100007, 0);
queue<int> q;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (druzyna[i] == 0) {
            q.push(i);
            druzyna[i] = 1;
        }
        while (!q.empty()) {
            int w = q.front();
            q.pop();
            for (int sasiad : t[w]) {
                if (druzyna[sasiad] == 0) {
                    if (druzyna[w] == 1) druzyna[sasiad] = 2;
                    else druzyna[sasiad] = 1;
                    q.push(sasiad);
                } else if (druzyna[w] == druzyna[sasiad]) {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << druzyna[i] << " ";
    }
}