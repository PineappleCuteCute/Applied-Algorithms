#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string> S;
    S.insert("abc");
    S.insert("xyz");
    S.insert("def");

    set<string>::iterator p;
    for(p = S.begin(); p != S.end(); p++) cout << *p << " "; cout << endl;
}