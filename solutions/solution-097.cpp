#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
void solve() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    int cur = 0;
    if (v[1] > v[cur]) cur = 1;
    if (v[2] > v[cur]) cur = 2;
    string ans = "";
    vector<char> c = {'R', 'G', 'B'};
    ans += c[cur];
    v[cur]--;
    int diff = -1;
    int cnt = 0;
    while (1) {
        int cand1 = (cur + 1) % 3;
        int cand2 = (cur + 2) % 3;
        int nxt = -1;
        if (cnt == 2) {
            int forced = 3 - diff;
            nxt = (cur + forced) % 3;
            if (v[nxt] == 0) break;
        } else {
            int cnt1 = v[cand1];
            int cnt2 = v[cand2];
            if (cnt1 == 0 && cnt2 == 0) break;
            if (cnt1 > cnt2) {
                nxt = cand1;
            } else if (cnt2 > cnt1) {
                nxt = cand2;
            } else {
                if (diff != 1) nxt = cand1;
                else nxt = cand2;
            }
        }
        int diff2 = (nxt - cur + 3) % 3;
        if (diff2 == diff) cnt++;
        else {
            diff = diff2;
            cnt = 1;
        }
        ans += c[nxt];
        v[nxt]--;
        cur = nxt;
    }
    cout << ans << '\n';;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}