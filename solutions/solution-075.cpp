#include <bits/stdc++.h>

using namespace std;

bool dfs(int indx, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &rec){
    if(rec[indx]) return true;
    if(vis[indx]) return false;
    vis[indx] = true; rec[indx] = true;
    for(int x : adj[indx]){
       if(dfs(x, adj, vis, rec)) return true;
    }
    rec[indx] = false;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            if(x){
                adj[i].push_back(j);
            }
        }
    }
    vector<bool> vis(n), rec(n);
    for(int i = 0; i < n; i++){
        if(!vis[i] && dfs(i, adj, vis, rec)){
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}