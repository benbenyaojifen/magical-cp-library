#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> result;
    while(!q.empty()){
        int node = q.front(); q.pop();
        result.push_back(node);
        for(int nxt : adj[node]){
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }
    vector<int> dist(n, -1e9);
    dist[0] = 1;
    vector<int> parent(n, -1);
    for(int u : result){
        if(dist[u] == -1e9) continue;
        for(int v : adj[u]){
            if(dist[u] + 1 > dist[v]){
                parent[v] = u;
                dist[v] = dist[u] + 1;
            }
        }
    }
    if(dist[n - 1] == -1e9){
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << dist[n - 1] << '\n';
        vector<int> path;
        for(int i = n - 1; i != -1; i = parent[i]) path.push_back(i);
        for(int i = path.size() - 1; i >= 0; i--) cout << path[i] + 1 << (i == 0 ? "\n" : " ");
    }
}