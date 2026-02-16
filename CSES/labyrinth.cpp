#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;
vector<vector<bool>> odwiedzony;
vector<vector<char>> sciezki;
queue<pair<int, int>> q;
int n, m;
int ax, ay, bx, by;
int dx[] = {1, -1, 0, 0}; 
int dy[] = {0, 0, 1, -1};
char kierunki[] = {'D', 'U', 'R', 'L'};

int main() {
    cin >> n >> m;
    v.resize(n, vector<char>(m));
    odwiedzony.resize(n, vector<bool>(m, false));
    sciezki.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string inp;
        cin >> inp;
        for(int j = 0; j < m; j++) {
            v[i][j] = inp[j];
            if (inp[j] == 'A') {
                ax = i;
                ay = j;
            }
            if (inp[j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }

    q.push({ax, ay});
    odwiedzony[ax][ay] = true;

    while (!q.empty()) {
        pair<int, int> obecne = q.front();
        q.pop();
        int cx = obecne.first;
        int cy = obecne.second;
        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (v[nx][ny] != '#' && !odwiedzony[nx][ny]) {
                    q.push({nx, ny});
                    odwiedzony[nx][ny] = true;
                    sciezki[nx][ny] = kierunki[i];
                }
            }
        }
    }

    string res;

    if(odwiedzony[bx][by] == false) {
        cout << "NO";
    }
    else {
        cout << "YES" << "\n";
        int x = bx;
        int y = by;
        while (x != ax || y != ay) {
            char ruch = sciezki[x][y];
            if (ruch == 'L') {
                y += 1;
                res += "L";
            } else if (ruch == 'R') {
                y -= 1;
                res += "R";
            } else if (ruch == 'U') {
                x += 1;
                res += "U";
            } else {
                x -= 1;
                res += "D";
            }
        }
        reverse(res.begin(), res.end());
        cout << res.size() << "\n";
        cout << res;
    }
}