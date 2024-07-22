//Dữ liệu
//4 4
//0 1 1 1
//1 1 1 0
//1 1 0 0
//1 1 1 0
//Kết quả
//6
//C++
#include <bits/stdc++.h>

using namespace std;

int maxRectangleArea(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();

    vector<int> heights(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                heights[j] = 0;
            } else {
                heights[j]++;
            }
        }

        vector<int> left(m), right(m, m);
        stack<int> st;

        for (int j = 0; j < m; ++j) {
            while (!st.empty() && heights[st.top()] >= heights[j]) {
                st.pop();
            }
            left[j] = st.empty() ? -1 : st.top();
            st.push(j);
        }

        while (!st.empty()) st.pop();

        for (int j = m - 1; j >= 0; --j) {
            while (!st.empty() && heights[st.top()] >= heights[j]) {
                st.pop();
            }
            right[j] = st.empty() ? m : st.top();
            st.push(j);
        }

        for (int j = 0; j < m; ++j) {
            int area = heights[j] * (right[j] - left[j] - 1);
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << maxRectangleArea(matrix) << endl;

    return 0;
}
