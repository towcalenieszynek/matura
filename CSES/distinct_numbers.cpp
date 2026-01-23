#include <bits/stdc++.h>
using namespace std;

int n;
int liczba;
set<int> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> liczba;
        v.insert(liczba);
    }
    cout << v.size();
}