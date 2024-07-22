#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    set<int> s;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        s.insert(x);
    }

    string operation;
    while(cin >> operation && operation != "#"){
        if(operation =="min_greater_equal"){
            int v;
            cin >> v;
            auto it = s.lower_bound(v);
            
        }
    }

}