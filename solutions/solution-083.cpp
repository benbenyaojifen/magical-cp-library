#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
vector<int> parent;
int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unite(int x, int y) {
    x = find(x); y = find(y);
    parent[x] = y;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        int leader; cin >> leader;
        for (int j = 1; j < c; j++) {
            int k; cin >> k;
            unite(leader, k);
        }
    }
    vector<int> ans;
    int root = find(1);
    for (int i = 1; i <= n; i++) {
        if (find(i) == root) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}