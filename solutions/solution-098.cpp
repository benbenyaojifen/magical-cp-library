#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int w; cin >> w;
    vector<unordered_set<int>> check(1); 
    unordered_set<int> frontier;
    for(int i = 0; i < w; i++){
        int c; cin >> c;
        check[0].insert(c);
        frontier.insert(c);
    }
    if (check[0].count(1)) {
        cout << "sacrifice bobhob314\n";
        return 0;
    }
    int time = 0;
    while(!frontier.empty()){
        unordered_set<int> next_frontier;
        for(int u : frontier){
            for(int v : adj[u]){
                if(!check.back().count(v)) next_frontier.insert(v);
            }
        } 
        if (next_frontier.empty()) break;
        time += 4; 
        if (check.size() <= time) check.resize(time + 1);
        check[time] = check[time - 4];
        for (int v : next_frontier) check[time].insert(v);
        frontier.swap(next_frontier);
    }
    queue<tuple<int,int,int>> nq; // node, time, dist
    nq.push({1, 0, 0});
    vector<unordered_set<int>> seen(n + 1);
    while(!nq.empty()){
        auto [cur, t, d] = nq.front(); nq.pop();
        for(int nxt : adj[cur]){
            int t2 = t + 1; 
            int timeKey = (t2 / 4) * 4;
            if (timeKey > time) timeKey = time;
            if (timeKey >= 0 && timeKey < check.size() && check[timeKey].count(nxt)) continue;
            if (seen[nxt].count(timeKey)) continue;
            seen[nxt].insert(timeKey);
            if (nxt == n){
                cout << d + 1 << '\n';
                return 0;
            }
            nq.push({nxt, t2, d + 1});
        }
    }
    cout << "sacrifice bobhob314" << '\n';
    return 0;
}
