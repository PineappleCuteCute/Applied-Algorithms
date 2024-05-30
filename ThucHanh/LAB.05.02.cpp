#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> duration(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> duration[i];
    }

    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    vector<int> earliestCompletionTime(n + 1, 0);

    // Push tasks with in-degree 0 into the queue
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
            earliestCompletionTime[i] = duration[i];
        }
    }

    int projectCompletionTime = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
            earliestCompletionTime[v] = max(earliestCompletionTime[v], earliestCompletionTime[u] + duration[v]);
        }

        projectCompletionTime = max(projectCompletionTime, earliestCompletionTime[u]);
    }

    cout << projectCompletionTime << endl;

    return 0;
}