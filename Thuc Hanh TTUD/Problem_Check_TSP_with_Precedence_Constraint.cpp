#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;

    vector<int> route(n);
    for(int i=0;i<n;++i){
        cin >> route[i];
    }

    vector<vector<int>> distance(n, vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> distance[i][j];
        }
    }

    int m; cin >> m;
    unordered_map<int, unordered_set<int>> constraints;
    for(int i=0;i<m;++i){
        int u, v;
        cin >> u >> v;
        constraints[u].insert(v);
    }

    unordered_map<int, int> position;
    for(int i=0;i<n;++i){
        position[route[i]] = i;
    }

    for(const auto& [u, vs] : constraints){
        for(int v : vs){
            if(position[u] >= position[v]){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int total_distance = 0;
    for(int i=0;i<n-1;++i){
        total_distance += total_distance[route[i] - 1][route[i + 1] - 1];
    }
    total_distance += distance[route[n - 1] - 1][route[0] - 1];
    cout << total_distance << endl;
    return 0;


}