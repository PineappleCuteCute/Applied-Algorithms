#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> Q;

    for(int i=0;i<5;i++){
        Q.push(i);
        cout << "push: " << i << endl;
    }

    while(!Q.empty()){
        int e = Q.front(); 
        Q.pop();
        cout << "pop: " << e << endl;
    }

}