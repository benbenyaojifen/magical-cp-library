#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> cycle;
bool dfs(int cur, vector<vector<int>> &adj, vector<int> &color, vector<int> &parent, vector<int> &depth){ 
    //0 = not visited, 1 = visiting, 2 = visited
    color[cur] = 1;
    for(int nxt : adj[cur]){
        if(color[nxt] == 0){
            parent[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
            if(dfs(nxt, adj, color, parent, depth)) return true; // found cycle already
        } else if(color[nxt] == 1){;
            int x = cur;
            cycle.push_back(nxt);
            while(x != nxt){
                cycle.push_back(x);
                x = parent[x];
            }
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }
    color[cur] = 2;
    return false;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; i++){
        int c; cin >> c;
        adj[i].push_back(c);
    }
    vector<int> color(n + 1, 0), parent(n + 1, -1), depth(n + 1, 0);
    // solve with colouring dfs
    dfs(1, adj, color, parent, depth); 
    int step = 0, entry = -1; // step from one to first cycle node from that path
    queue<int> q;
    q.push(1);
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> in_cycle(n + 1, 0);
    for(int v : cycle) in_cycle[v] = 1;
    dist[1] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(in_cycle[cur]){
            step = dist[cur];
            entry = cur;
            break;
        }
        for(int nxt : adj[cur]){
            if(dist[cur] + 1 < dist[nxt]){
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    if(k < step){
        int cur = 1;
        while(k--){
            cur = adj[cur][0];
        }
        cout << cur << '\n';
        return 0;
    }
    int remain = (k - step) % cycle.size();
    int pos = find(cycle.begin(), cycle.end(), entry) - cycle.begin();
    int ans = cycle[(pos + remain) % cycle.size()];
    cout << ans << '\n';
    return 0;
}