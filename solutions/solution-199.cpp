#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void dfs(int src, vector<vector<int>>& adj, vector<vector<pair<int, int>>>& trees, unordered_map<int, int>& mp, int prev){
    if(src == 0){
        for(int nxt : adj[src]){
            if(nxt == prev) continue;
            dfs(nxt, adj, trees, mp, src);
        }
    } else { 
        for(int nxt : adj[src]){
            if(nxt == prev) continue;
            int tree = mp[prev];
            trees[tree].push_back({prev, nxt});
            mp[nxt] = tree;
            dfs(nxt, adj, trees, mp, src);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    int k = 0;
    unordered_map<int, int> mp;
    mp[0] = 0;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; 
        if(u == 1 || v == 1){
            k++;
            u == 1 ? mp[v - 1] = v - 1 : mp[u - 1] = u - 1;
        }
        u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    vector<vector<pair<int, int>>> trees(2 * 1e5 + 1);
    dfs(0, adj, trees, mp, -1);
    cout << k + 1 << endl;
    vector<vector<int>> nodes(2 * 100000 + 1);
    for (int i = 0; i < n; i++) {
        int t = mp[i];
        nodes[t].push_back(i);
    }
    for(int i = 0; i < nodes.size(); i++){
        if(nodes[i].empty()) continue;
        cout << nodes[i].size() << endl;
        for(auto[u, v] : trees[i]){
            cout << u + 1 << " " << v + 1 << endl;
        }
    }
}