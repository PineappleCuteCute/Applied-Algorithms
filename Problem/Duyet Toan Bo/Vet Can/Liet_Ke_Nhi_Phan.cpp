#include<bits/stdc++.h>
using namespace std;

int A[1000];
int n;

void printSo1(){
    for(int i=0;i<=1;i++){
        cout << A[i] << ", ";
    }
    cout << endl;
}

void TRY(int k){
    for(int i=0;i<=1;i++){
        A[k] = i;

        if(k==n){
            printSo1();
        }
        else{
            TRY(k+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    TRY(1);
    return 0;



}