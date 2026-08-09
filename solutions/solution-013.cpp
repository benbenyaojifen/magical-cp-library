#include <bits/stdc++.h>
using namespace std;
struct Node{
    int d, col, r, c;// d is distance, col = colorm, r= row, c = col
    // priority_queue is a max heap by default so we need to change it
    bool operator<(const Node &o) const {
        if (d != o.d) return d > o.d;// smaller distance has higher priority
        return col > o.col; // if tie, then smaller colour has higher priority
    }
};
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    auto out = g;
    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<int>> best(n, vector<int>(m, 0));
    priority_queue<Node> pq;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] != 0){
                dist[i][j] = 0;
                best[i][j] = g[i][j];
                pq.push({0, g[i][j], i, j});
            }
        }
    }
    // multi source bfs with distance up to k
    while (!pq.empty()){
        Node cur = pq.top(); pq.pop();
        if (cur.d > dist[cur.r][cur.c]) continue;
        if (cur.d == dist[cur.r][cur.c] && cur.col > best[cur.r][cur.c]) continue;
        for (auto [dr, dc] : dir){
            int nr = cur.r + dr, nc = cur.c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m){
                int nd = cur.d + 1;
                if (nd > k) continue;
                if (nd < dist[nr][nc] || (nd == dist[nr][nc] && cur.col < best[nr][nc])){
                    dist[nr][nc] = nd;
                    best[nr][nc] = cur.col;
                    pq.push({nd, cur.col, nr, nc});
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == 0 && dist[i][j] <= k) out[i][j] = best[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << out[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
