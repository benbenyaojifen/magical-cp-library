#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
//idea is to use toposort to ensure that u always before v for every direct edge u - v and then accumulate cnt of paths 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    vector<int> res;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front(); q.pop();
        res.push_back(node);
        for(int nxt : adj[node]){
            if(!--indegree[nxt]) q.push(nxt);
        }
    }
    vector<int> dp(n + 1); dp[1] = 1; // base case
    for(int i = 0; i < res.size(); i++){
        int cur = res[i];
        for(int nxt : adj[cur]){
            dp[nxt] += dp[cur];
            dp[nxt] %= mod;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}