#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int n;
int p[MAX];
stack<int> chuong;
queue<int> hanh_lang;
string s;

void input(){
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> p[i];
    }

    for(int i=n-1;i>=0;i--){
        chuong.push(p[i]);
    }

    cin >> s;
}

void solve(){
    int lens = s.length();
    for(int i=0;i<lens;i++){
        if(s[i] == 'C'){
            if(!chuong.empty()){
                int Chuong = chuong.top();
                chuong.pop();
                hanh_lang.push(Chuong);
            }
        }
        else{
            if(!hanh_lang.empty()){
                int HanhLang = hanh_lang.front();
                hanh_lang.pop();
                chuong.push(HanhLang);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    for(int i=0;i<n;i++){
        cout << chuong.top() << " ";
        chuong.pop();
    }
}