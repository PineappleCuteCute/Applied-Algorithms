#include <iostream>
#include <vector>
#include <algorithm> // For equal

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n), b(m);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        
        if (n == m && equal(a.begin(), a.end(), b.begin())) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    
    return 0;
}
