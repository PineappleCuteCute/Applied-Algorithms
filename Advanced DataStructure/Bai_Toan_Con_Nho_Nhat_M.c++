#include<bits/stdc++.h>
using namespace std;

/*Bài tập minh họa (P.02.03.01). 
Cho dãy a0, a1, ..., aN-1. 
Cho số nguyên dương K, ta cần thực hiện K truy vấn, 
mỗi truy vấn dạng RMQ(i, j) trả về chỉ số của phần tử nhỏ nhất của dãy ai, ai+1, . . ., aj.*/

/*Tiềnxửlý
• TínhM[i,j]làchỉsốcủaphầntửnhỏnhấtcủadãyconbắtđầutừaj vàcó2i phầntử,
vớii=0,1,2,...,log2(N+1) vàj=0,1,2,...,N-1.*/

/* BàitoánconnhỏnhấtM[0,j]=j,j=0,...,N-1 
• Công thức truy hồi
M[i, j] = M[i-1, j] nếu a[M[i-1, j]] < a[M[i-1, j+2i-1] 
        = M[i-1, j+2i-1], ngược lại*/

/*preprocessing(){
for (i = 0; i < N; i++) M[0,i] = i;
for(j=0;2j ≤N;j++){ for(i=0;i+2j -1<N;i++){
if a[M[j-1,i]] < a[M[j-1,i+2j-1]] then{ M[j,i] = M[j-1,i];
}else{
M[j,i] = M[j-1,i+2j-1];
} }
} }*/

void preprocessing(int N, int M[][100001], int a[]){
    for(int i = 0; i < N; i++){
        M[0][i] = i;
    }
    for(int j = 1; pow(2, j) <= N; j++){
        for(int i = 0; i + pow(2, j) - 1 < N; i++){
            if(a[M[j-1][i]] < a[M[j-1][i + (int)pow(2, j-1)]]){
                M[j][i] = M[j-1][i];
            }
            else{
                M[j][i] = M[j-1][i + (int)pow(2, j-1)];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int M[100001][100001]; 
    int a[100001];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    preprocessing(N, M, a);

    return 0;
}