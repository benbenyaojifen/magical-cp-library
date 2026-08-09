#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
vector<int> parent;
int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}
void unite(int x, int y) {
    x = find(x); y = find(y);
    parent[x] = y;
}
void solve() {
    int n; cin >> n;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n / 2; i++) {
        unite(i, 2 * i);
    }
    unordered_map<int, vector<int>> indx, val;
    for (int i = 1; i <= n; i++) {
        int p = find(i);
        indx[p].push_back(i);
        val[p].push_back(v[i]);
    }
    for (auto &a : indx) {
        auto &index = a.second;
        auto &value = val[a.first];
        sort(index.begin(), index.end());
        sort(value.begin(), value.end());
        if (index != value) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}