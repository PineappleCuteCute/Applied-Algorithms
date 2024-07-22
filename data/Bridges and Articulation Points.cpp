//Input
//10 12
//1 10
//10 2
//10 3
//2 4
//4 5
//5 2
//3 6
//6 7
//7 3
//7 8
//8 9
//9 7
//Output
//4  3
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> adj;
vector<int> visited, parent, disc, low;
set<int> articulationPoints;
set<pair<int, int>> bridges;
int time_;

void dfs(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++time_;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
                bridges.insert({min(u, v), max(u, v)});

            if (parent[u] != -1 && low[v] >= disc[u])
                articulationPoints.insert(u);
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (parent[u] == -1 && children > 1)
        articulationPoints.insert(u);
}

int main() {
    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    visited.assign(N + 1, 0);
    parent.assign(N + 1, -1);
    disc.assign(N + 1, 0);
    low.assign(N + 1, 0);
    time_ = 0;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i])
            dfs(i);
    }

    cout << articulationPoints.size() << " " << bridges.size() << endl;

    return 0;
}
