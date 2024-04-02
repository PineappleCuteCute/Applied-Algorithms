#include<bits/stdc++.h>
using namespace std;

const int N = 15;
const int INF = 1e9;
int n, maxCap;
int C[2*N + 1][2*N + 1];
int curLoad = 0, curCost = 0, bestCost = INF, cmin;
int x[2*N + 1], bestX[2*N + 1];
bool visited[2*N + 1];

bool check(int i, int k){
    if(visited[i]==true) return false;
    if(i>n) return visited[i-n];
    if(i<=n && curLoad == maxCap) return false;
    return true;
}

void updateCurBest(){
    int i;
    if(curCost + C[i][0] < bestCost){
        bestCost = curCost + C[x[2 * n]][0];
        for (int i=0;i<=2 * n;i++){
            bestX[i] = x[i];
        }
    }
}

void TRY(int k){
    for(int i=1;i<=2*n;i++){
        if(check(i, k)){
            x[k] = i;
            //Cap nhat so nguoi tren xe
            if (i <= n) curLoad++;
            else curLoad--;
            visited[i] = true;
            curCost += C[x[k-1]][i];
            if (k==2 * n) updateCurBest(); //?
            else{
                if(curCost + (2 * n + 1 - k) * cmin < bestCost) TRY(k + 1);
            }
            //tra lai gia tri ban dau
            curCost -= C[x[k-1]][i];
            visited[i] = false;
            if (i <= n) curLoad--;
            else curLoad++;
        }
    }
}

void input(){
    cin >> n >> maxCap;
    for(int i=0;i<=2 * n;i++){
        for(int j=0;j<=2*n;j++){
            cin >> C[i][j];
            if(i != j) cmin = min(cmin, C[i][j]);//cmin(cmin, C[i][j]); //?
        }
    }
}

int main(){
    freopen("data.inp", "r", stdin);
    input();
    x[0] = 0;
    memset(visited, 0, sizeof(visited));
    TRY(1);
    cout << bestCost << endl;
}