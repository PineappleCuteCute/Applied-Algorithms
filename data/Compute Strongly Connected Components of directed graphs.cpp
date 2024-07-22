//Input
//8 13
//1 2
//1 8
//2 3
//2 6
//3 6
//4 3
//4 6
//5 4
//6 5
//7 1
//7 2
//7 6
//8 7
//Output
//3
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs1(int v, const vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u, adj, visited, s);
        }
    }
    s.push(v);
}

void dfs2(int v, const vector<vector<int>> &adjT, vector<bool> &visited) {
    visited[v] = true;
    for (int u : adjT[v]) {
        if (!visited[u]) {
            dfs2(u, adjT, visited);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<vector<int>> adjT(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }

    stack<int> s;
    vector<bool> visited(N + 1, false);

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, s);
        }
    }

    fill(visited.begin(), visited.end(), false);
    int sccCount = 0;

    while (!s.empty()) {
        int v = s.top();
        s.pop();
        if (!visited[v]) {
            dfs2(v, adjT, visited);
            sccCount++;
        }
    }

    cout << sccCount << endl;

    return 0;
}
