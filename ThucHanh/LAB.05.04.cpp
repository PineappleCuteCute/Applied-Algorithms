#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 10005;
vector<int> adj[MAXN];
vector<int> match;
vector<bool> visited;

bool augment(int u) {
    if (visited[u]) return false;
    visited[u] = true;
    for (int v : adj[u]) {
        if (match[v] == -1 || augment(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    match.assign(m + 1, -1);
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int task;
            cin >> task;
            adj[i].push_back(task);
        }
    }

    int max_tasks = 0;
    for (int i = 1; i <= n; ++i) {
        visited.assign(n + 1, false);
        if (augment(i)) {
            max_tasks++;
        }
    }

    cout << max_tasks << endl;

    return 0;
}