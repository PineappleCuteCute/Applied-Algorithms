#include<bits/stdc++.h>
using namespace std;

int main(){
    //tang toc do doc ghi code
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> V;
    V.push_back(1); V.push_back(2);
    for(int i=3;i<=10;i++){
        V.push_back(i);
    }
    for(int i=0;i<V.size();i++){
        cout << V[i] << " ";
    }
    cout << endl;
    V.erase(V.begin(), V.begin() + 3);
    for(int i=0;i<V.size();i++){
        cout << V[i] << " ";
    }
    cout << endl;
}