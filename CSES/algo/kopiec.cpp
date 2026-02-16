#include <bits/stdc++.h>
using namespace std;

void wstaw(vector<int>& drz, int& n, int el) {
    // n++;
    // drz[n] = el;
    // logika majaca sens tylko do tablic

    drz.push_back(el);
    n++;

    int w = n;
    while (w > 1 && drz[w] > drz[w/2]) {
        swap(drz[w], drz[w/2]);
        w /= 2;
    }
}

void przywroc(vector<int>& drz, int& n, int i) {
    int lewy = 2*i;
    int prawy = 2*i + 1;
    int maks = i;
    if (lewy <= n && drz[lewy] > drz[maks]) {
        maks = lewy;
    }
    if (prawy <= n && drz[prawy] > drz[maks]) {
        maks = prawy;
    }
    if (maks > i) {
        swap(drz[i], drz[maks]);
        przywroc(drz, n, maks);
    }
}

void usun(vector<int>& drz, int& n) {
    drz[1] = drz[n];
    n--;
    przywroc(drz, n, 1);
}


void drop_tree(vector<int>& drz, int&n) {
    int k = 2;
    int i = 1;
    while(i <= n) {
        cout << drz[i] << " ";
        if (i+1 == k) {
            i = k;
            k *= 2;
            cout << "\n";
        }
        else {
            i++;
        }
    }
}

int main() {
    int k = 3;
    vector<int> drz = {0, 15, 6, 10, 4, 2, 8};
    int n = drz.size() - 1;
    drop_tree(drz, n);
    cout << "\n";
    // wstaw(drz, n, 16);
    // drop_tree(drz, n);
    // srand(time(NULL));
    // for(int i = 0; i < 10; i++) {
    //     wstaw(drz, n, rand() % 25);
    //     drop_tree(drz, n);
    //     cout << "\n";
    // }
    usun(drz, n);
    drop_tree(drz, n);
    cout << "\n";
}