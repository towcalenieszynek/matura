#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    //tworzymy ta tablice gdzie dostepne_autostrady[miasto] bedzie pokazywac miasta 
    //z ktorych prowadzi autostrada, i interesuja nas tylko przypadki w ktorych idziemy
    // w prawo
    vector<int> dostepne_autostrady(n, -1);
    for(int i = 0; i < n; i++) {
        if (m[i] != -1 && m[i] >= i) {
            dostepne_autostrady[m[i]] = i;
        }
    }

    int dp[k+1][n+1];

    // // dostanie sie 0 autostradami do miasta 0 zajmuje 0 dni, 
    // // ogolnie dostanie sie do miasta 0 zajmuje 0 dni
    // dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[0][i] = i;
    }
    //dostanie sie do miasta 0 zawsze zajmuje 0 dni
    for(int b = 0; b <= k; b++) {
        dp[b][0] = 0;
    }

    for(int ile_auto = 1; ile_auto <= k; ile_auto++)
    {
        for(int miasto = 1; miasto <= n; miasto++) {
            if(dostepne_autostrady[miasto] != -1) {
                dp[ile_auto][miasto] = min(dp[ile_auto - 1][miasto], dp[ile_auto - 1][miasto - dostepne_autostrady[miasto]] + 1);
            }
        }
    }

    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }


}
