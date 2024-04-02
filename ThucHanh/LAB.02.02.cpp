#include <iostream>
#include <vector>
using namespace std;

bool can_cut_material(int H, int W, int n, const vector<pair<int, int>>& cuts) {
    vector<vector<bool>> material(H, vector<bool>(W, false));

    for (const auto& cut : cuts) {
        int h = cut.first;
        int w = cut.second;

        if (h > H || w > W) // Check if the cut size is valid
            return false;

        bool found = false;
        for (int i = 0; i <= H - h; ++i) {
            for (int j = 0; j <= W - w; ++j) {
                bool fits = true;
                for (int x = i; x < i + h; ++x) {
                    for (int y = j; y < j + w; ++y) {
                        if (material[x][y]) {
                            fits = false;
                            break;
                        }
                    }
                    if (!fits)
                        break;
                }
                if (fits) {
                    found = true;
                    for (int x = i; x < i + h; ++x) {
                        for (int y = j; y < j + w; ++y) {
                            material[x][y] = true;
                        }
                    }
                    break;
                }
            }
            if (found)
                break;
        }
        if (!found)
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int H, W;
    cin >> H >> W;

    int n;
    cin >> n;

    vector<pair<int, int>> cuts(n);
    for (int i = 0; i < n; ++i) {
        cin >> cuts[i].first >> cuts[i].second;
    }

    cout << can_cut_material(H, W, n, cuts) << endl;

    return 0;
}
