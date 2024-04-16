/*
Bài tập minh họa 2.2 (P.02.02.04). 
Cho dãy số không âm a[1], a[2], . . ., a[n]. 
Cho trước giá trị Q, hãy tìm dãy con (gồm một số phần tử đứng liên tiếp cạnh nhau) 
dài nhất mà có tổng nhỏ hơn hoặc bằng Q.
*/

/*
• Thuật toán sử dụng 2 trỏ
• Biến L di chuyển từ trái qua phải; biến R chạy từ trái
qua phải trên dãy 
• Độ phức tạp O(n)
*/

//Algorithm
/*
res = 0; S = 0;
L = 1;
for R = 1 to n do {
   S = S + a[R];
   while S > Q do {
S = S – a[L]; L = L + 1; }
res = max(res, R – L + 1); }
Output(res);
*/

#include<bits/stdc++.h>
using namespace std;

void twoPoints(int a[], int n, int Q){
    int res = 0;
    int S = 0;
    int L = 1;
    for(int R=1;R<n;R++){
        S += a[R];
        while(S > Q){
            S -= a[L];
            L += 1;
        }
        res = max(res, R - L + 1);
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a[100001];
    int n, Q;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> Q;

    twoPoints(a, n, Q);
}