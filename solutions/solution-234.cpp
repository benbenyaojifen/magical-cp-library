#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e17; //❄️
void solve() {
    int n, m, k; cin >> n >> m >> k;
    int l = k - 1, r = n - k;
    if (l > r) swap(l, r);
    int best = 1;
    for (int i = 0; i <= r; i++) {
        int l_time = m - 2 * i + 1;
        if (l_time < 0) break; 
        int l_max = min({l, i, l_time});
        if (l_max < 0) continue;
        int cnt = 1 + l_max + i;
        if (cnt > best) best = cnt;
    }
    cout << best << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}