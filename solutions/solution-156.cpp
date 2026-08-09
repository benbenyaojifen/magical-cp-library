#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
void solve() {
     int n, m, h; cin >> n >> m >> h;
     vector<int> old(n), cur(n), upd(n);
     for (int i = 0; i < n; i++) {
        int x; cin >> x;
        old[i] = x; cur[i] = x;
     }
     vector<pair<int,int>> op;
     for (int i = 0; i < m; i++) {
        int pos, val; cin >> pos >> val;
        pos--;
        op.emplace_back(pos, val);
     }
    int update = 1;
    for (auto[pos, val] : op) {
        if (upd[pos] != update) {
            upd[pos] = update;
            cur[pos] = old[pos];
        }
        if (cur[pos] + val > h) {
            update++;
        } else {
            cur[pos] += val;
        }
    }
    for (int i = 0; i < cur.size(); i++) {
        if (upd[i] != update) cout << old[i] << " \n"[i == cur.size() - 1];
        else cout << cur[i] << " \n"[i == cur.size() - 1];
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}