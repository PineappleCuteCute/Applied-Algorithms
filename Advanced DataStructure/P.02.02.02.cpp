#include<bits/stdc++.h>
using namespace std;

int a[10000][10000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int a1, b1, c1, d1;
    cout << "Nhap a, b, c, d:";
    cin >> a1 >> b1 >> c1 >> d1;

    // Tính mảng cộng dồn
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    // Thực hiện truy vấn
    int result = a[c1][d1] - a[c1][b1 - 1] - a[a1 - 1][d1] + a[a1 - 1][b1 - 1];
    cout << "Ket qua truy van: " << result << endl;

    return 0;
}
