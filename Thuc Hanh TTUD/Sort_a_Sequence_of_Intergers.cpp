#include<bits/stdc++.h>
using namespace std;

int a[1000000];

void sort(int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(n);
}