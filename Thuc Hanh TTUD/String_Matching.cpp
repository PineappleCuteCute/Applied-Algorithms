#include<bits/stdc++.h>
using namespace std;

int Count(string P, string T){
    int count = 0;
    int t = T.length();
    int p = P.length();

    for(int i=0;i<t-p;i++){
        if(T.substr(i, p) == P){
            count++;
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string P, T;
    //read input 
    getline(cin, P);
    getline(cin, T);
    
    cout << Count(P, T);



}