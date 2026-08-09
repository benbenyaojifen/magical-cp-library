#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
void solve() {
    int n, s, x; cin >> n >> s >> x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        sum += v;
    }
    if (sum <= s && (s - sum) % x == 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}