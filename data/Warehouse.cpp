//Input
//6 6 2
//6 8 5 10 11 6
//1 2 2 3 3 2
//
//Output
//24
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int n, f[N][102], T, D, a[N], t[N], res;

void inp()
{
    ios_base :: sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> T >> D;
    for(int i = 1 ; i <= n; i ++) cin >> a[i];
    for(int i = 1 ; i <= n; i ++) cin >> t[i];
}

void proc()
{
    for(int i = 1 ; i <= n; i ++) {
        for(int k = t[i]; k <= T; k++) {
            for(int j = max(0, i - D); j <= i - 1; j ++) {
                f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
            }
            res = max(res, f[i][k]);
        }
    }
    cout << res << "\n";
}

int main()
{
    inp();
    proc();
}

