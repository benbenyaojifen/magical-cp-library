#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    for (int i = 0; i < n; i++) {
        ll cnt1 = 0, cnt2 = 0;
        for (int j = i + 1; j < n; j++) {
            if (abs(v[i] + mx) > abs(v[j] + mx)) cnt1++;
        }
        for (int j = i + 1; j < n; j++) {
            if (abs(v[i] - mx) > abs(v[j] - mx)) cnt2++;
        }
        cout << max(cnt1, cnt2) << " ";
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}