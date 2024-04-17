#include<bits/stdc++.h>
using namespace std;
/*Bài tập minh họa (P.02.03.01). 
Cho dãy a0, a1, ..., aN-1. 
Cho số nguyên dương K, ta cần thực hiện K truy vấn, 
mỗi truy vấn dạng RMQ(i, j) trả về chỉ số của phần tử nhỏ nhất của dãy ai, ai+1, . . ., aj.*/

/*
Thuật toán trực tiếp
• Với mỗi truy vẫn RMQ(i, j), ta duyệt dãy ai, ai+1, . . ., aj. 
• ĐộphứctạpO(j-i)
*/

/*
RMQ(a, i, j){
min = +¥; min_idx = -1; 
for k = i to j do {
ifmin>a[k]then {
min = a[k];, min_idx = k;
} }
  return min_idx;
}
*/

void RMQ(int a[], int i, int j){
    int min = 1000001;
    int min_idx = -1;
    for(int k=i;k<=j;k++){
        if(min > a[k]){
            min = a[k];
            min_idx = k;
        }
    }
    cout << min_idx << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int a[100001];
    cin >> i >> j;
    for(int k=i;k<=j;k++){
        cin >> a[k];
    }
    RMQ(a, i, j);
    return 0;
}