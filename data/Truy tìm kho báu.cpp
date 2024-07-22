//Dữ liệu vào
//10
//2 4 7
//4 2   10
//4 6 2
//5 5 7
//1 3 9
//1 5 1
//1 1 3
//3 1 5
//3 3 6
//2 2 2
//Kết quả:
//26
//Giải thích:
//Đường đi tối ưu đi qua các kho báu có toạ độ lần lượt   là (1, 1), (1, 3), (2,4) và (5,5) có tổng lượng vàng là 3 + 9 + 7 + 7 = 26
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Treasure {
    long long x, y, gold;
};

bool compareTreasures(const Treasure &a, const Treasure &b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int n;
    cin >> n;

    vector<Treasure> treasures(n);
    for (int i = 0; i < n; ++i) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].gold;
    }

    // Sắp xếp các kho báu theo thứ tự tăng dần của cả hai toạ độ x và y
    sort(treasures.begin(), treasures.end(), compareTreasures);

    long long maxGold = 0;
    vector<long long> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = treasures[i].gold;
        for (int j = 0; j < i; ++j) {
            if (treasures[i].x >= treasures[j].x && treasures[i].y >= treasures[j].y) {
                dp[i] = max(dp[i], dp[j] + treasures[i].gold);
            }
        }
        maxGold = max(maxGold, dp[i]);
    }

    cout << maxGold << endl;

    return 0;
}
