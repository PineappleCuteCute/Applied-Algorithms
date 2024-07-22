#include <iostream>
#include <vector>

using namespace std;

int count_positive_integer_solutions(int n, int M, vector<int>& a) {
    // Create a DP array with (M+1) dimensions, initialized to 0
    vector<int> dp(M + 1, 0);

    // Base case: There's exactly one way to achieve the sum 0 (using no elements)
    dp[0] = 1;

    // Fill the DP array
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i - 1]; j <= M; ++j) {
            dp[j] += dp[j - a[i - 1]];
        }
    }

    // The result is in dp[M]
    return dp[M];
}

int main() {
    int n, M;
    cin >> n >> M;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int result = count_positive_integer_solutions(n, M, a);
    cout << result << endl;

    return 0;
}
