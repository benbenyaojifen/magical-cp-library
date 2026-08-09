#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e17; //❄️
vector<int> parent;
struct edge {
    int u, v, w, s;
    edge(int uu, int vv, int ww, int ss) : u(uu), v(vv), w(ww), s(ss) {}
    bool operator<(const edge& o) const {
        if (o.w != w) return w < o.w;
        return s > o.s;
    }
};
int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}
void unite(int x, int y) {
    x = find(x); y = find(y);
    parent[x] = y;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m, d; cin >> n >> m >> d;
    vector<edge> edges;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(u, v, w, i < n - 1 ? 1 : 0);
    }
    sort(edges.begin(), edges.end());
    vector<edge> use;
    int cnt = 0, ans = 0, last = -1;
    for (int i = 0; i < edges.size(); i++) {
        if (cnt == n - 1) break;
        auto[u, v, w, s] = edges[i];
        if (find(u) != find(v)) {
            use.emplace_back((edge){u, v, w, s});
            unite(u, v);
            cnt++;
            last = i;
            if (!s) {
                ans++;
            }
        }
    }
    if (edges[last].w <= d && edges[last].s == 0) {
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int i = 0; i < last; i++) {
            auto[u, v, w, s] = edges[i];
            if (w == edges[last].w && s == edges[last].s) continue;
            if (find(u) != find(v)) unite(u, v);
        }
        for (int i = last + 1; i < edges.size(); i++) {
            auto[u, v, w, s] = edges[i];
            if (w <= d && s && find(u) != find(v)) {
                ans--; break;
            } 
        }
    }
    cout << ans << '\n';
    return 0;
}