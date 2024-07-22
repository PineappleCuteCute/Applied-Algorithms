#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
int a[MAX], b[MAX];
int n, m;
int T;

void input(){
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> a[j];
        }

        cin >> m;
        for(int k=0;k<m;k++){
            cin >> b[k];
        }
    }
}

void solve(){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i] == b[j]){
                count++;
            }
        }
    }
    cout << count << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}