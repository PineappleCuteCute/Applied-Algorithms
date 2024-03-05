#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int MAX_N = 1000000;

int min(int a, int b) {
    return a < b ? a : b;
}

void buildTree(vector<int>& tree, const vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(tree, arr, 2 * node, start, mid);
        buildTree(tree, arr, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(const vector<int>& tree, int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return numeric_limits<int>::max();
    } else if (start >= left && end <= right) {
        return tree[node];
    } else {
        int mid = (start + end) / 2;
        int leftMin = query(tree, 2 * node, start, mid, left, right);
        int rightMin = query(tree, 2 * node + 1, mid + 1, end, left, right);
        return min(leftMin, rightMin);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> tree(4 * MAX_N);
    buildTree(tree, arr, 1, 0, n - 1);

    cin >> m;

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int left, right;
        cin >> left >> right;
        sum += query(tree, 1, 0, n - 1, left, right);
    }

    cout << sum << endl;

    return 0;
}
