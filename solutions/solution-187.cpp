#include <bits/stdc++.h>

using namespace std;

vector<int> bellman_ford(int v, vector<vector<int>>& edge, int src){
    vector<int> dist(v + 1, 1e8);
    dist[src] = 0;
    for(int i = 0; i < v; i++){
        for(auto e : edge){
            int u = e[0], v_ = e[1], w = e[2];
            if(dist[u] != 1e8 && dist[u] + w < dist[v_]){
                if(i == v - 1) return {-1};
                dist[v_] = dist[u] + w;
            }
        }
    }
    return dist;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> edge;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back(vector<int>{u, v, w});
    }
    int src = 1;
    vector<int> ans = bellman_ford(n, edge, src);
    cout << ans[n] << '\n';
    return 0;
}