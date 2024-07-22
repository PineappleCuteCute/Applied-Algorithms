#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int MAX = 100005;
int a[MAX];
int n;
int T;

void input(){
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> a[j];
        }
    }
}

void solve(){
    unordered_map<int, int> dp; // dp[x] sẽ lưu độ dài của dãy con đẹp kết thúc bằng x
    int longest = 0;

    for (int i = 0; i < n; ++i) {
            dp[a[i]] = dp[a[i] - 1] + 1;
            longest = max(longest, dp[a[i]]);
    }
    cout << longest << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}