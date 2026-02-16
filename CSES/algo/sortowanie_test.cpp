#include <bits/stdc++.h>
using namespace std;

struct Student {
    int ocena;
    string imie;

    bool operator< (const Student& other) const {
        return ocena > other.ocena;
    }
};


int main() {
    priority_queue<Student> pq;
    pq.push({1, "Tomek"});
    pq.push({3, "Marek"});
    pq.push({2, "Ania"});
    cout << pq.top().ocena << pq.top().imie;
    pq.pop();
    cout << pq.top().ocena << pq.top().imie;
}