#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    deque<int> dq;
    vector<int> dist(n + 1, INT_MAX);
    unordered_set<int> office;
    int k; cin >> k;
    for(int i = 0; i < k; i++){
        int c; cin >> c;
        office.insert(c);
    }
    dist[*office.begin()] = 0;
    dq.push_front(*office.begin());
    while(!dq.empty()){
        int cur = dq.front(); dq.pop_front();
        for(int nxt : adj[cur]){
            if(office.count(nxt) && dist[nxt] != 0){
                dist[nxt] = 0;
                dq.push_front(nxt);
            } else if(dist[cur] + 1 < dist[nxt]){
                dist[nxt] = dist[cur] + 1;
                dq.push_back(nxt);
            }
        }
    }
    int ans = *max_element(dist.begin() + 1, dist.end());
    cout << ans << '\n';
}