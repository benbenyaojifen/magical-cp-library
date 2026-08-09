#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll INF = INT_MAX;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    vector<int> dist1(n, INF), dist2(n, INF);
    int s1 = 0, s2 = n - 1;
    dist1[s1] = 0; dist2[s2] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1, pq2;
    pq1.push({0, s1}); pq2.push({0, s2});
    while(!pq1.empty()){
        auto[d, u] = pq1.top(); pq1.pop();
        if(d > dist1[u]) continue;
        for(auto[w_u_v, v] : adj[u]){
            int v_cost = dist1[u] + w_u_v;
            if(v_cost < dist1[v]){
                dist1[v] = v_cost;
                pq1.push({v_cost, v});
            }
        }
    }
    while(!pq2.empty()){
        auto[d, u] = pq2.top(); pq2.pop();
        if(d > dist2[u]) continue;
        for(auto[w_u_v, v] : adj[u]){
            int v_cost = dist2[u] + w_u_v;
            if(v_cost < dist2[v]){
                dist2[v] = v_cost;
                pq2.push({v_cost, v});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < dist1.size(); i++){
        ans = max(ans, dist1[i] + dist2[i]);
    }
    cout << ans << '\n';
    return 0;
}