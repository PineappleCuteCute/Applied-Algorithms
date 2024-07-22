#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void solve(){
    int sum = 0;
    for(int i=0;i<n;i++){ 
        sum += a[i];
    }
    cout << sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

}