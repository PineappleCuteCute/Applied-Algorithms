#include<bits/stdc++.h>
using namespace std;

void get_max(int a[], int i, int j){
    int max=0;
    for(int k=i;k<=j;k++){
        if(a[k] > max){
            max = a[k];
        }
    }
    cout << max << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int v;
    int i, j;
    int a[100001];
    cin >> v;
    cin >> j;
    for(int i=0;i<=j;i++){
        a[i] = v;
    }
}