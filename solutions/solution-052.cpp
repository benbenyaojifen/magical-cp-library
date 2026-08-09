#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj, components;
vector<bool> visited;

void dfs(int u, vector<int>& comp){
    visited[u] = true;
    comp.push_back(u + 1); // 1 based index
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v, comp);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n); visited.resize(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int c;
            cin >> c;
            if(c == 1){
                adj[i].push_back(j); // add edge from node i to j
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            vector<int> comp;
            dfs(i, comp);
            sort(comp.begin(), comp.end());
            components.push_back(comp);
        }
    }
    sort(components.begin(), components.end());
    for(auto &comp : components){
        for(int node : comp){
            cout << node << " ";
        }
        cout << '\n';
    }
    return 0;
}