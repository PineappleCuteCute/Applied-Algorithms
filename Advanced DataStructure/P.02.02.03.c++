/*
Bài tập minh họa 2.1 (P.02.02.03). 
Cho dãy số a[1], a[2], . . ., a[n] được sắp xếp theo thứ tự tăng dần (các phần tử đôi một khác nhau). 
Cho trước giá trị Q, hãy đếm số cặp 2 chỉ số i và j sao cho a[i] + a[j] = Q.
*/


/*
• Thuật toán sử dụng 2 trỏ
• Biến i di chuyển từ trái qua phải; biến j chạy từ phải qua trái trên dãy 
• Độ phức tạp O(n)
*/

//Algorithm:
/*
res = 0;
i = 1; j = n;
while i < j do {
if a[i] + a[j] = Q then {
res = res + 1; i = i + 1; j = j – 1;
}else if a[i] + a[j] < Q then i = i + 1;
else
j = j – 1;
}
Output(res);
*/

//programming code:
#include<bits/stdc++.h>
using namespace std;

void twoPoints(int a[], int n, int Q){
    int res = 0;
    int i = 1;
    int j = n;
    while(i < j){
        if(a[i] + a[j] == Q){
            res += 1;
            i += 1;
            j -= 1;
        }
        else if(a[i] + a[j] < Q){
            i += 1;
        }
        else{
            j -= 1;
        }
    }
    cout << res << endl;
}


// Hàm sắp xếp mảng
void sortArray(int a[], int n){
    sort(a, a + n);
}

int main(){
    //Tăng tốc độ đọc ghi
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a[100001];
    int n , Q;
    //Nhập mảng bất kì 
    cout << "Nhap n :" << endl;
    cin >> n;
    cout << "Nhap vao mang a: " << endl;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sortArray(a, n); // Sắp xếp mảng
    cout << "Mang sau khi sap xep la: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    cout << "Nhap Q = a[i] + a[j]: ";
    cin >> Q;

    cout << "So cap i, j sao cho a[i] + a[j] = Q la: ";
    twoPoints(a, n, Q);
    
}