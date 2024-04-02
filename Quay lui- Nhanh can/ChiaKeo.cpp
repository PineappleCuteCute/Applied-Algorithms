#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int MOD = 1e9 + 7;
int n, K, takenSweets = 0, ans = 0;
int x[N];

void TRY(int k){
    int startVal = k == K ? n - takenSweets : 0;
    for ( int i = 0; i <= n - takenSweets; i++) {
        x[k] = i;
        takenSweets += i;
        if(k==K) {
            ans = (ans + 1) % MOD;
            for (int j = 1; j <= K; j++){
                cout << x[j] << " ";
            }
            cout << endl;
        }
        else TRY(k+1);
        takenSweets -= i;
    }
}

int main(){
    cin >> n >> K;
    
}