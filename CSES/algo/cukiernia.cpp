#include <bits/stdc++.h>
using namespace std;
#define END "\n"

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int minimum = c[n - 1] + 1;
    int wynik = 0;
    for(int i = n-1; i >= 0; i--)
    {
        minimum = min(minimum, c[i]);
        wynik += minimum;
    }
    cout << wynik << "\n";

}