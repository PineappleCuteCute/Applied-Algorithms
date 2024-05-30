#include<bits/stdc++.h>
using namespace std;

int A[1000];
int n;

void printSo1(){
    for(int i=1;i<=n;i++){
        cout << A[i] << ", ";
    }
    cout << endl;
}

void TRY(int k){
    cout << "Call TRY at " << k << endl;
    for(int i=0;i<=1;i++){
        A[k] = i;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


}