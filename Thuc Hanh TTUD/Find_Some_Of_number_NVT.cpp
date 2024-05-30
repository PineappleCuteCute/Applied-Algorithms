#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a[10];
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}