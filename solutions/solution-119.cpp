#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    vector<int> a(10), b(10);
    for (int i = 0; i < 20; i++) {
        if (i < 10) cin >> a[i];
        else cin >> b[i - 10];
    }
    ll ans = INF;
    vector<int> ta;
    vector<bool> ca(10);
    auto dfs = [&] (auto &&self, int pos, int cnt) -> void {
        if (cnt == 5) {
            vector<int> tb;
            for (int i = 0; i < 10; i++) {
                if (!ca[i]) tb.push_back(i);
            }
            ll pa = 0, pb = 0;
            for (int i = 0; i < ta.size(); i++) {
                pa += a[ta[i]];
            }
            for (int i = 0; i < tb.size(); i++) {
                pb += a[tb[i]];
            }
            for (int i = 0; i < ta.size(); i++) {
                ll na = pa - a[ta[i]] + b[ta[i]];
                for (int j = 0; j < tb.size(); j++) {
                    ll nb = pb - a[tb[j]] + b[tb[j]];
                    ans = min(ans, abs(na - nb));
                }
            }
            return;
        }
        if (pos == 10) return;
        ta.push_back(pos);
        ca[pos] = 1;
        self(self, pos + 1, cnt + 1);
        ta.pop_back();
        ca[pos] = 0;
        self(self, pos + 1, cnt);
    };
    dfs(dfs, 0, 0);
    cout << ans << '\n';
    return 0;
}