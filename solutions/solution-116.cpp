#include <bits/stdc++.h>
using namespace std;
pair<int,int> bfs(int start, const vector<vector<int>> &g){
    int n = g.size() - 1;
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0; q.push(start);
    int far = start;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dist[u] > dist[far]) far = u;
        for(int v : g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {far, dist[far]};
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n == 1){
        cout << 0 << "\n";
        return 0;
    }
    auto a = bfs(1, g);
    auto d = bfs(a.first, g);
    cout << d.second << "\n";
    return 0;
}
