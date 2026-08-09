#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
const int MM = 1000005;
int Z[MM];
int cnt[MM];
int head[MM];
int nxt[MM];
int val[MM];
int q_head[MM];
int q_nxt[105];
int q_r[105];
int q_id[105];
void solve() {
    fill(q_head, q_head + MM, -1);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> active;
    int q_cnt = 0;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (q_head[l] == -1) {
            active.push_back(l);
        }
        q_r[q_cnt] = r;
        q_id[q_cnt] = i;
        q_nxt[q_cnt] = q_head[l];
        q_head[l] = q_cnt++;
    }
    vector<ll> ans(q);
    for (int l : active) {
        vector<pair<int, int>> current_q;
        int cur_q = q_head[l];
        while (cur_q != -1) {
            current_q.push_back({q_r[cur_q], q_id[cur_q]});
            cur_q = q_nxt[cur_q];
        }
        sort(current_q.begin(), current_q.end());
        int max_r = current_q.back().first;
        int m = max_r - l + 1;
        Z[0] = m;
        for (int i = 1, L = 0, R = 0; i < m; i++) {
            Z[i] = 0;
            if (i <= R) Z[i] = min(R - i + 1, Z[i - L]);
            while (i + Z[i] < m && s[l - 1 + Z[i]] == s[l - 1 + i + Z[i]]) {
                Z[i]++;
            }
            if (i + Z[i] - 1 > R) {
                L = i;
                R = i + Z[i] - 1;
            }
        }
        cnt[0] = 1;
        int max_val = 0;
        ll current_sum = 0;
        for (int i = 1; i <= m + 1; i++) head[i] = -1;
        int q_indx = 0;
        for (int i = 1; i <= m; i++) {
            int cur = head[i];
            while (cur != -1) {
                cnt[val[cur]]--;
                cur = nxt[cur];
            }
            while (max_val > 0 && cnt[max_val] == 0) {
                max_val--;
            }
            int dpi = max_val + 1;
            current_sum += dpi;

            while (q_indx < current_q.size() && current_q[q_indx].first - l + 1 == i) {
                ans[current_q[q_indx].second] = current_sum;
                q_indx++;
            }
            if (i < m && Z[i] > 0) {
                cnt[dpi]++;
                if (dpi > max_val) max_val = dpi;
                int exp = i + Z[i] + 1;
                if (exp <= m) {
                    val[i] = dpi;
                    nxt[i] = head[exp];
                    head[exp] = i;
                }
            }
        }
        for (int i = 0; i <= max_val; i++) cnt[i] = 0;
        q_head[l] = -1;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';;
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