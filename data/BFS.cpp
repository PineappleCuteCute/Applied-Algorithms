//Input
//6 7
//2 4
//1 3
//3 4
//5 6
//1 2
//3 5
//2 3
//
//Output
//1 2 3 4 5 6
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int N, E;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    for(int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            bfs(i);
        }
    }
}

int main() {
    cin >> N >> E;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Sắp xếp danh sách kề để đảm bảo các đỉnh kề được duyệt theo thứ tự từ điển
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(1);

    return 0;
}
