#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
void solve() {
    int n; cin >> n;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) cin >> pre[i];
    //prefix max
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (pre[i] >= pre[i - 1]) ans++;
        pre[i] = max(pre[i], pre[i - 1]);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}