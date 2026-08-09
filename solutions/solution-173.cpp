#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, t, k, v; cin >> n >> t >> k >> v;
    vector<bool> pos(n + 1);
    for (int i = 0; i < v; i++) {
        int c; cin >> c;
        pos[c] = 1;
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= t; i++) {
        if (pos[i]) cnt++;
    }
    if (cnt < k) {
        for (int i = t; i >= 1; i--) {
            if(pos[i]) continue;
            else pos[i] = 1;
            cnt++;
            ans++;
            if(!(cnt < k)) break;
        }
    }
    for (int i = 2; i <= n; i++) {
        if(i + t - 1 > n) break;
        if(pos[i - 1]) cnt--;
        if(pos[i + t - 1]) cnt++;
        if(cnt < k) {
            for (int j = i + t - 1; j >= i; j--) {
                if(pos[j]) continue;
                else pos[j] = 1;
                cnt++;
                ans++;
                if(!(cnt < k)) break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}