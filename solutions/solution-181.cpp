#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> bfs(int start, const vector<vector<int>> &g){
    int n = g.size() - 1;
    vector<int> d(n + 1, -1);
    queue<int> q;
    d[start] = 0; q.push(start);
    int far = start;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(d[u] > d[far]) far = u;
        for(int v : g[u]){
            if(d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return {far, d};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }
    //farthest from 1 -> A
    auto [A, d1] = bfs(1, g);
    //farthest from A -> B, also get dist from A
    auto tmp = bfs(A, g);
    int B = tmp.first;
    vector<int> distA = move(tmp.second);
    //dist from B
    auto tmp2 = bfs(B, g);
    vector<int> distB = move(tmp2.second);
    // For each node v, answer = max(distA[v], distB[v]) + 1
    for(int v = 1; v <= n; v++){
        cout << max(distA[v], distB[v]) + 1 << "\n";
    }
    return 0;
}
