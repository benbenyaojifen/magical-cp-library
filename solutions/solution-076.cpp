#include <bits/stdc++.h>

using namespace std;

void dfs(int n, int indx, pair<int, int> bad, vector<bool> &visited, vector<vector<int>> &adj){
    if(visited[indx]) return;
    visited[indx] = true;
    if(indx == n) return;
    for(int c : adj[indx]){
        if(!(indx == bad.first && c == bad.second)) dfs(n, c, bad, visited, adj);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    unordered_map<int, pair<int, int>> day;
    for(int i = 0; i <m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        day[i] = make_pair(x, y);
    }
    for(int i = 0; i < m; i++){
        pair bad = day[i];
        vector<bool> visited(n, false);
        dfs(n - 1, 0, bad, visited, adj);
        if(visited[n - 1]){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}