
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
#define int long long
void solve() {
    int n, m, k; cin >> n >> m >> k;
    //we want to precompute how much each update will kill
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    unordered_map<int, int> kill, first;
    unordered_set<int> used;
    string s; cin >> s;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L') cur--;
    else cur++;
    if (!first.count(cur)) {
        first[cur] = i + 1;
    }
}
for (int i = 0; i < n; i++) {
    int x = a[i];
    int indx = lower_bound(b.begin(), b.end(), x) - b.begin();
    int best_time = INF, dif = 0;
    if (indx < m) {
        int d = b[indx] - x;
        if (first.count(d)) {
            if (first[d] < best_time) {
                best_time= first[d];
                dif = d;
            }
        }
    }
    if (indx > 0) {
        int d = b[indx - 1] - x;
        if (first.count(d)) {
            if (first[d] < best_time) {
                best_time = first[d];
                dif = d;
            }
        }
    }
    if (best_time != INF) {
        kill[dif]++;
    }
}
    int pos = 0, dead = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L') pos--;
        else pos++;
        if (!used.count(pos)) {
            if (kill.count(pos)) dead += kill[pos];
            used.insert(pos);
        }
        cout << n - dead << " \n"[i == s.size() - 1];
    }
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}