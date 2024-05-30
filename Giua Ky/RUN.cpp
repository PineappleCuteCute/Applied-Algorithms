#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
int n;
int a[MAX];
int res;

void input(){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void solve(){
    int count = 0;
    for(int i=0;i<n;i++){
        if(a[i] < a[i-1]) count++;
    }
    res = count;
}

int main(){
    cin >> n;
    input();
    solve();
    cout << res + 1 << endl;
}