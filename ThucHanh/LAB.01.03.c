#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

void buildTree(int tree[], int arr[], int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(tree, arr, 2 * node, start, mid);
        buildTree(tree, arr, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(int tree[], int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return INT_MAX;
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
    ios_base::sync_with_stdio
    int n, m;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n); // Dynamically allocate memory for arr
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int *tree = (int *)malloc(sizeof(int) * 4 * n); // Dynamically allocate memory for tree
    if (tree == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(arr); // Free dynamically allocated memory for arr before exiting
        return 1;
    }
    
    buildTree(tree, arr, 1, 0, n - 1);

    scanf("%d", &m);

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int left, right;
        scanf("%d %d", &left, &right);
        sum += query(tree, 1, 0, n - 1, left, right);
    }

    printf("%d\n", sum);

    free(arr);
    free(tree);

    return 0;
}
