#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> cost;
const int INF = 0x3f3f3f3f;
struct cmp {
    bool operator()(const tuple<int,int,int> &a, const tuple<int,int,int> &b) const {
        int af = get<0>(a), bf = get<0>(b);
        int au = get<1>(a), bu = get<1>(b);
        int ap = get<2>(a), bp = get<2>(b);
        if(af == INF && bf == INF) {
            int ca = cost[{au, ap}];
            int cb = cost[{bu, bp}];
            return ca > cb;
        }
        return af > bf;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        cost[{a, b}] = c;
        cost[{b, a}] = c;
        if(d) c = INF;

        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, cmp> pq;
    pq.push({0, 1, 1});
    vector<bool> vis(n + 1);
    int dan_cnt = 0, ans = 0;
    while(!pq.empty()){
        auto [c, u, pre] = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        dan_cnt += (c == INF);
        ans += (u == 1 ? 0 : cost[{u, pre}]);
        for(auto [cc, v] : adj[u]){
            if(!vis[v]){
                pq.push({cc, v, u});
            }
        }
    }
    cout << dan_cnt << " " << ans << '\n';
}
