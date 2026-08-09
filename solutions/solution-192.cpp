#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Edge = pair<int, ll>;
vector<vector<Edge>> g;
ll farDist;
void dfs(int u, int p, ll acc){
    farDist = max(farDist, acc);
    for(auto [v, w] : g[u]){
        if(v == p) continue;
        dfs(v, u, acc + w);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m; cin >> m;
    vector<tuple<int,int,ll>> edges;
    edges.reserve(m);
    int maxv = 0;
    ll sumW = 0;
    for(int i = 0; i < m; i++){
        int u, v; ll w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        maxv = max(maxv, max(u, v));
        sumW += w;
    }
    int n = maxv + 1;
    g.assign(n, {});
    for(auto [u, v, w] : edges){
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    // Only need farthest distance from 0
    farDist = 0;
    dfs(0, -1, 0);
    ll ans = 2LL * sumW - farDist;
    cout << ans << "\n";
    return 0;
}
