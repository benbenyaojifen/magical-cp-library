#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> color, depth, parent;
int ans = -1;
void dfs(int u){
    color[u] = 1; // visiting
    for (int v : adj[u]){
        if (ans != -1) return; // cycle already found
        if (color[v] == 0){
            parent[v] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
        } else if (color[v] == 1){
            ans = depth[u] - depth[v] + 1; // foudn unique cycle
            return;
        }
    }
    color[u] = 2; // done
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int tc = 0; tc < 5; tc++){
        int m; cin >> m;
        adj.assign(101, {});
        color.assign(101, 0);
        depth.assign(101, 0);
        parent.assign(101, -1);
        ans = -1;
        int start = -1;
        for (int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            if (i == 0) start = u;
            adj[u].push_back(v);
        }
        dfs(start);
        cout << ans << "\n";
    }
    return 0;
}
