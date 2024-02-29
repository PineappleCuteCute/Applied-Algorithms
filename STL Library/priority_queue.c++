#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> PQ;
    PQ.push(1); PQ.push(100); PQ.push(7); PQ.push(1000);

    while(!PQ.empty()){
        int e = PQ.top(); 
        PQ.pop();
        cout << e << endl;

    }
}