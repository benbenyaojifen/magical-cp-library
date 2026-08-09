#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> node(n + 1, -1);
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        vector<bool> used(5);
        for(int c : adj[i]){
            if(node[c] != -1){
                used[node[c]] = 1;
            }
        }
        for(int j = 1; j <= 4; j++){
            if(!used[j]){
                node[i] = j;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << node[i] << (i == n ? "\n" : "");
    }
    return 0;
}