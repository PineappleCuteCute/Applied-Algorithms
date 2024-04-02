#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

const int MAX_N = 1e4 + 5;
const int MAX_M = 1e6 + 5;

int N, M, s, t;
std::vector<int> adjList[MAX_N];
int capacity[MAX_N][MAX_N];
int parent[MAX_N];

struct Node {
    int vertex, flow;
    Node(int v, int f) : vertex(v), flow(f) {}
};

int bfs(int source, int sink) {
    memset(parent, -1, sizeof(parent));
    parent[source] = -2;
    std::queue<Node> q;
    q.push(Node(source, INT_MAX));

    while (!q.empty()) {
        int cur = q.front().vertex;
        int flow = q.front().flow;
        q.pop();

        for (int i = 0; i < adjList[cur].size(); i++) {
            int next = adjList[cur][i];
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = std::min(flow, capacity[cur][next]);
                if (next == sink)
                    return new_flow;
                q.push(Node(next, new_flow));
            }
        }
    }

    return 0;
}

int max_flow(int source, int sink) {
    int max_flow = 0;
    int flow;

    while ((flow = bfs(source, sink)) != 0) {
        max_flow += flow;
        int cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            capacity[prev][cur] -= flow;
            capacity[cur][prev] += flow;
            cur = prev;
        }
    }

    return max_flow;
}

int main() {
    std::cin >> N >> M;
    std::cin >> s >> t;
    s--, t--;

    for (int i = 0; i < M; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        u--, v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        capacity[u][v] += c;
    }

    std::cout << max_flow(s, t) << std::endl;

    return 0;
}