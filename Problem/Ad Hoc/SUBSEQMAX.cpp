#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a[1000005];
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    int ans = -2e9;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            //Tong cua trong so chuoi con bat dau tu i va ket thuc o j
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += a[k];
            }
            if(sum > ans){
                ans = sum;
            }
        }
    }
    cout << ans;
    return 0;
}