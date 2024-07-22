//Input
//7 5
//4
//1 5
//6 2
//2 2
//4 3
//Output
//1
//C++
#include <iostream>
#include <vector>

using namespace std;

int canPerformCut(int H, int W, int n, vector<pair<int, int>>& cuts) {
    int totalArea = H * W;
    int remainingArea = totalArea;
    int markH = H;
    int markW = W;

    for (int i = 0; i < n; ++i) {
        if (cuts[i].first > H) {
            if (cuts[i].first > W) {
                return -1;
            } else {
                if (markW >= cuts[i].first) {
                    markW -= cuts[i].first;
                } else return -1;
            }
        }

        if (cuts[i].first > W) {
            if (cuts[i].first > H) {
                return -1;
            } else {
                if (markH >= cuts[i].first) {
                    markH -= cuts[i].first;
                } else return -1;
            }
        }

        if (cuts[i].second > W) {
            if (cuts[i].second > H) {
                return -1;
            } else {
                if (markH >= cuts[i].second) {
                    markH -= cuts[i].second;
                } else return -1;
            }
        }

        if (cuts[i].second > H) {
            if (cuts[i].second > W) {
                return -1;
            } else {
                if (markW >= cuts[i].second) {
                    markW -= cuts[i].second;
                } else return -1;
            }
        }


        remainingArea -= cuts[i].first * cuts[i].second;
    }

    return remainingArea;
}

int main() {
    int H, W;
    cin >> H >> W;

    int n;
    cin >> n;

    vector<pair<int, int>> cuts(n);
    for (int i = 0; i < n; ++i) {
        cin >> cuts[i].first >> cuts[i].second;
    }

    int out = canPerformCut(H, W, n, cuts);

    if (out >= 0) {
        cout << 1;
    } else cout << 0;

    return 0;
}
