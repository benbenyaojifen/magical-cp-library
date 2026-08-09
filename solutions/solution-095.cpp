#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = n; i < n + 100; i++) {
        string c = to_string(i);
        int cnt = 0;
        for (int j = 0; j < c.size(); j++) {
            cnt += c[j] - '0';
        }
        if (n + cnt == i) ans++;
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