#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
void solve() {
    int n; cin >> n;
    vector<char> v(n); vector<bool> vis(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int cnt = 0;
    for (int i = 0; i < n;) {
        if (vis[i]) {
            cout << i + 2 << '\n';
            return;
        }
        vis[i] = 1;
        if (v[i] == 'R') i++;
        else i--;
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