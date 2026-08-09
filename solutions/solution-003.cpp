#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i = 0; i < indegree.size(); i++){
        if(!indegree[i]) q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        cnt++;
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(!--indegree[nxt]) q.push(nxt);
        }
    } 
    if(cnt == n){
        cout << "Y" << '\n';
    } else {
        cout << "N" << '\n';
    }
}