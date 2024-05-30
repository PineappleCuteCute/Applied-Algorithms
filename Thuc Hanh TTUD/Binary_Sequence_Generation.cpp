#include<bits/stdc++.h>
using namespace std;

void generateBinarySequence(string prefix, int n){
    if(n==0){
        cout << prefix << endl;
    }
    else{
        generateBinarySequence(prefix + "0", n - 1);
        generateBinarySequence(prefix + "1", n - 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    generateBinarySequence("", n);
    return 0;
}