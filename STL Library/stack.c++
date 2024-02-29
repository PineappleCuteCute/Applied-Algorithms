#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> S;

    for(int i=0;i<5;i++){
        S.push(i);
        cout << "push: " << i << endl;
    }

    while(!S.empty()){
        int e = S.top(); S.pop(); 
        cout << "pop: " << e << endl;
    }
}