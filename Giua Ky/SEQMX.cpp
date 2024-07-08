#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Calculate the sum of the first 'k' elements
    double current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += a[i];
    }

    double max_avg = current_sum / k;

    // Use a sliding window to calculate the sum of the subarrays of length >= k
    for (int i = k; i < n; i++) {
        current_sum += a[i];           // Add the new element to the current sum
        current_sum -= a[i - k];       // Subtract the element that is left behind

        double current_avg = current_sum / k;
        max_avg = max(max_avg, current_avg);

        // Expand the window to consider larger subarrays
        for (int j = k + 1; j <= i + 1; j++) {
            double new_avg = accumulate(a.begin() + i - j + 1, a.begin() + i + 1, 0.0) / j;
            max_avg = max(max_avg, new_avg);
        }
    }

    cout << fixed << setprecision(5) << max_avg << endl;

    return 0;
}
