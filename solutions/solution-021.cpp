#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r; cin >> n >> r;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> distRabbit(n + 1, INT_MAX);
    queue<int> q;
    for (int i = 0; i < r; i++){
        int r; cin >> r;
        distRabbit[r] = 0;
        q.push(r);
    }
    int s, t; 
    cin >> s >> t;
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (distRabbit[v] == INT_MAX) {
                distRabbit[v] = distRabbit[u] + 1;
                q.push(v);
            }
        }
    }

    //from s to get parent to reconstruct from s to t path
    vector<int> parent(n + 1, -1);
    queue<int> q2;
    parent[s] = s;
    q2.push(s);
    while (!q2.empty() && parent[t] == -1){
        int u = q2.front(); q2.pop();
        for (int v : adj[u]){
            if (parent[v] == -1){
                parent[v] = u;
                q2.push(v);
            }
        }
    }
    // reconstruct path from t to s
    int ans = INT_MAX;
    for (int cur = t; ; cur = parent[cur]){
        ans = min(ans, distRabbit[cur]);
        if (cur == s) break;
    }
    cout << ans << '\n';
    return 0;
}
