//Input
//8 12 5 6
//1 1 0 0 0 0 1 0 0 0 0 1
//1 0 0 0 1 1 0 1 0 0 1 1
//0 0 1 0 0 0 0 0 0 0 0 0
//1 0 0 0 0 0 1 0 0 1 0 1
//1 0 0 1 0 0 0 0 0 1 0 0
//1 0 1 0 1 0 0 0 1 0 1 0
//0 0 0 0 1 0 1 0 0 0 0 0
//1 0 1 1 0 1 1 1 0 1 0 1
//
//Output
//7

//C++
#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x, y, steps;
};

bool isValidMove(int** maze, bool** visited, int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y];
}

int escapeMaze(int** maze, int n, int m, int start_x, int start_y) {
    bool** visited = new bool*[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = new bool[m]();
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    queue<Point> q;
    q.push({start_x, start_y, 1});
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (p.x == 0 || p.x == n - 1 || p.y == 0 || p.y == m - 1) {
            return p.steps;
        }

        for (int i = 0; i < 4; ++i) {
            int new_x = p.x + dx[i];
            int new_y = p.y + dy[i];

            if (isValidMove(maze, visited, new_x, new_y, n, m)) {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y, p.steps + 1});
            }
        }
    }

    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, start_x, start_y;
    cin >> n >> m >> start_x >> start_y;

    int** maze = new int*[n];
    for (int i = 0; i < n; ++i) {
        maze[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }

    cout << escapeMaze(maze, n, m, start_x - 1, start_y - 1) << endl;

    for (int i = 0; i < n; ++i) {
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}
