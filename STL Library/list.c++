#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    list<int> L;
    for(int i = 1;i<=5;i++){
        L.push_back(i);
    }

    list<int>::iterator p;
    p = L.begin();
    advance(p, 2);
    L.insert(p, 2, 6); //insert 2 occurrences of 6 after position p
    for(p = L.begin(); p!= L.end(); p++) cout << *p << " ";
}