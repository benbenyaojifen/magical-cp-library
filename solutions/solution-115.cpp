#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 4, m = 4, cnt = 0;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x; cin >> x;
            if(x){
                adj[i].push_back(j);
                adj[j].push_back(i);
                if(i < j) cnt++;
            }
        }
    }
    if(cnt != 3){
        cout << "No" << '\n';
         exit(0);
    }
    vector<bool> vis(n);
    queue<int> q;
    q.push(0); vis[0] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
    bool good = 1;
    for(int i = 0; i < n; i++){
        if(!vis[i]) good = 0;
    }
    if(good) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}