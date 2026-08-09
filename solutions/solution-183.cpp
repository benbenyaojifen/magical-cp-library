#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    auto mex = [&](vector<int>& a) {
        unordered_set<int> s;
        for (int i = 0; i < a.size(); i++) {
            s.insert(a[i]);
        }
        for (int i = 0; ; i++) {
            if (!s.count(i)) return i;
        }
    };
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        int diff = 0 - v[i];
        vector<int> tmp(n);
        for (int j = 0; j < n; j++) {
            tmp[j] = v[j] + diff;
        }
        ans = max(ans, mex(tmp));
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