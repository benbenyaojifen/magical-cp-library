#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<int> &parent, vector<int> & colour, vector<int>& cycle, bool &found){
    if(found) return;
    colour[u] = 1;
    for(int nxt : adj[u]){
        if(found) return;
        if(colour[nxt] == 0){
            parent[nxt] = u;
            dfs(nxt, adj, parent, colour, cycle, found);
        } else if(colour[nxt] == 1){
            // find parent and build cycle
            int cur = u;
            cycle.push_back(nxt);
            while(cur != nxt){
                cycle.push_back(cur);
                cur = parent[cur];
            }
            reverse(cycle.begin(), cycle.end());
            found = true; return;
        }
    }
    colour[u] = 2;
}
vector<int> find_cycle(vector<vector<int>> &adj){
    vector<int> colour(adj.size()), parent(adj.size()); // if colour[i] == 0, it is not visited, colour[1] = visiting, colour[2] = visited
    vector<int>cycle;
    bool found = 0;
    for(int i = 1; i < adj.size() && !found; i++){
        if(colour[i] == 0) dfs(i, adj, parent, colour, cycle, found);
    }
    return cycle;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i = 1; i < indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    } 
    int visited = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop(); visited++;
        for(int nxt : adj[cur]){ 
            if(!(--indegree[nxt])) q.push(nxt);
        }
    }
    if(visited == n){
        cout << "IMPOSSIBLE" << '\n';
    } else {
        vector<int> cycle = find_cycle(adj);
        cout << cycle.size() + 1 << '\n';
        for(int i = 0; i < cycle.size(); i++){
            cout << cycle[i] << " ";
        }
        cout << cycle[0] << "\n";
    }
    return 0;
}