#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for(int i = 0; i < n; i++){
        int c; cin >> c;
        for(int j = 0; j < c; j++){
            int con; cin >> con;
            con--;
            indegree[i]++;
            adj[con].push_back(i);
        }
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0) q.push(i);
    } 
    while(!q.empty()){
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(int nxt : adj[cur]){
            if(--indegree[nxt] == 0) q.push(nxt);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }
    return 0;
}