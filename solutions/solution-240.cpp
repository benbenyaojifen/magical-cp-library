#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e17; //❄️
#define int long long
void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> seen(n + 2); // mex is at most n + 1;
    for (int i = 0; i < v.size(); i++) {
        if (0 <= v[i] && v[i] <= n + 1) {
            seen[v[i]] = 1;
        }
    }
    int mex = 0;
    while (seen[mex]) mex++;
    cout << min(mex, k - 1) << '\n';
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}