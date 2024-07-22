//Input
//6
//3 2 4 5 6 1
//Output
//6

#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;
int const MOD = 1e9+7;
int n, a[maxn];
int temp[maxn];

// Hàm hợp nhất 2 mảng và trả về số lượng cặp nghịch đảo khi hợp nhất.

int _merge(int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left, inv_count = 0;
    while ((i <= mid) && (j <= right)) {
        if (a[i] <= a[j])   temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            inv_count = (inv_count + (mid - i + 1)) % MOD;
        }
    }
    // Copy những phần tử còn lại của nửa bên trái (nếu còn) vào mảng trung gian
    while (i <= mid) temp[k++] = a[i++];
    // Copy những phần tử còn lại của nửa bên phải (nếu còn) vào mảng trung gian
    while (j <= right) temp[k++] = a[j++];
    // Copy những phần tử đã được hợp nhất vào mảng gốc
    for (i = left; i <= right; i++)     a[i] = temp[i];
    return inv_count;
}

// An recursive function that sorts the input array and returns the number of inversions in the array.

int mergeSort (int left, int right){
    int mid, inv_count = 0;
    if (right > left) {
        // Divide the array into two parts and call mergeSort() for each of the parts
        mid = (right + left) / 2;
        // Inversion count will be sum of inversions in left-part, right-part and number of inversions in merging
        inv_count = (inv_count + mergeSort(left, mid)) % MOD;
        inv_count = (inv_count + mergeSort(mid + 1, right)) % MOD;
        inv_count = (inv_count + _merge(left, mid, right))% MOD;
    }
    return inv_count;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++)     cin >> a[i];
    cout << mergeSort(1, n);
    return 0;
}
