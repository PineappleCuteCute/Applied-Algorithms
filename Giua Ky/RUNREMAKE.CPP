#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int n;
int a[MAX];

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void solve(){
        int count = 0;
    for(int i=0;i<n;i++){
        if(a[i] < a[i-1]) count ++;
    }
    cout << count + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    return 0;
}