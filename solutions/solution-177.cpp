#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
#define int long long
vector<int> parent;
struct node {
    int c, x, y;
    node(int c, int x, int y) : c(c), x(x), y(y){}
};
struct edge {
    int u, v; double d;
    edge(int u, int v, double d) : u(u), v(v), d(d){}
    bool operator<(const edge& other) const {
        return d < other.d;
    }
};
int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unite(int x, int y) {
    x = find(x), y = find(y);
    parent[x] = y;
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;
    vector<node> vv;
    vector<edge> e;
    for (int i = 0; i < n; i++) {
        int c = i + 1, x, y; cin >> x >> y;
        vv.emplace_back(c, x, y);
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        e.emplace_back(x, y, 0);
    }
    for (int i = 0; i < vv.size(); i++) {
        auto [c, x, y] = vv[i];
        for (int j = i + 1; j < vv.size(); j++) {
            auto[cc, xx, yy] = vv[j];
            double dist = sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
            e.emplace_back(c, cc, dist);
        }
    }
    sort(e.begin(), e.end());
    int cnt = 0;
    double ans = 0;
    for (int i = 0; i < e.size(); i++) {
        auto[u, v, d] = e[i];
        if(find(u) != find(v)){
            unite(u, v);
            cnt++;
            ans += d;
        }
        if (cnt == n - 1) break;
    }
    cout << fixed << setprecision(2) << ans << '\n';
    return 0;
}