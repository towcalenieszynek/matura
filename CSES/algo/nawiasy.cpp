#include <bits/stdc++.h>
using namespace std;

bool solve(string ciag) {
    vector<int> stos;
    // { - 0; [ - 1; ( - 2
    for(char nawias : ciag) 
    {
        if (nawias == '{') stos.push_back(0);
        else if (nawias == '[') stos.push_back(1);
        else if (nawias == '(') stos.push_back(2);
        else {
            if (nawias == '}')
            {
                if (stos.back() == 0) stos.pop_back();
                else return false;
            }
            else if (nawias == ']')
            {
                if (stos.back() == 1) stos.pop_back();
                else return false;
            }
            else
            {
                if (stos.back() == 2) stos.pop_back();
                else return false;
            }
        }
    }
    if (stos.empty()) return true;
    else return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> stos;
    // { - 0; [ - 1; ( - 2
    string ciag;
    for(int x = 0; x < n; x++) {
       cin >> ciag;
       cout << solve(ciag) << endl;
    }
}