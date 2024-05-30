#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int k; cin >> k;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int res = -2e9;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += a[k];
                if(sum > res){
                    res = sum;
                }
            }

        }
    }
    
}