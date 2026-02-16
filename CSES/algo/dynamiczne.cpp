#include <bits/stdc++.h>
using namespace std;

int main() {
    int k = 6;
    int n = 3;
    int c[n] = {1, 2, 3};
    int dp[n+1][k+1];
    dp[0][0] = 0;
    for(int j = 1; j <= k; j++) {
        dp[0][j] = INT_MAX - 1;
    }
    for(int i = 1; i <= n; i++) {
        for (int j = 0; j < c[i-1]; j++) {
            dp[i][j] = dp[i-1][j];
            // j to kwoty, i dopoki kwota jest mniejsza niz najwyzszy nominal w nowym zestawie
            // to i tak nic sie zmieni wzgledem poprzedniego przypadku
        }
        for (int j = c[i - 1]; j <= k; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j - c[i - 1]] + 1);
        }
    }
    
    for(int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
} 